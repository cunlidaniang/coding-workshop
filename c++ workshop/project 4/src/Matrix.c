#include"head.h"
#include"Matrix.h"

//creat a matrix with row rows and col columns and random entry values.
Matrix * create_matrix(const size_t row, const size_t col){
    if(row <= 0 || col <= 0){
        return NULL;
    }
    Matrix * pNew = (Matrix *) malloc(sizeof(Matrix) );
    pNew->row = row;
    pNew->col = col;
    size_t size = row * col;
    pNew->entry = (float *) aligned_alloc(32 , sizeof(float) * size);
    srand((unsigned)time(NULL));
    for(size_t i = 0;i < size;i++){
        pNew->entry[i] = rand() / (float)(RAND_MAX);
    }
    return pNew;
}
//delete a matrix.
void delete_matrix(Matrix * p){
    if(p == NULL){
        return;
    }
    if(p->entry != NULL){
        free(p->entry);
    }
    free(p);
}
//print Matrix in bash.
void print_matrix(const Matrix * const pMatrix){
    if(pMatrix == NULL){
        return;
    }
    for(size_t i = 0;i < pMatrix->row;i++){
        for(size_t j = 0;j < pMatrix->col;j++){

            printf("%f  ", pMatrix->entry[(i) * pMatrix->col + (j)]);
        }
        printf("\n");
    }
}
//multiply two Matrix A and B in an plain way using several loops.
Matrix * matmul_plain(const Matrix * const pA, const Matrix * const pB){
    if(pA == NULL || pB == NULL){
        return NULL;
    }
    size_t row1 = pA->row;
    size_t col1 = pA->col;
    size_t row2 = pB->row;
    size_t col2 = pB->col;
    if(col1 != row2){
        return NULL;
    }
    Matrix * pC = (Matrix *) malloc(sizeof(Matrix) );
    pC->row = row1;
    pC->col = col2;
    pC->entry = (float *) aligned_alloc(32 , sizeof(float) * row1 * col2);
    memset(pC->entry,0,sizeof(pC->entry));
    for(size_t i = 0;i < row1;i++){
        for(size_t j = 0;j < col2;j++){
            for(size_t k = 0;k < col1;k++){
                pC->entry[i * col2 + j] += pA->entry[i * col1 + k] * pB->entry[k * col2 + j];
            }
        }
    }
    return pC;
}
//multiply two Matrix A and B in an advanced way using SIMD and openMP.
Matrix * matmul_improved(const Matrix * const pA, const Matrix * const pB){
    if(pA == NULL || pB == NULL){
        return NULL;
    }
    size_t row1 = pA->row;
    size_t col1 = pA->col;
    size_t row2 = pB->row;
    size_t col2 = pB->col;
    if(col1 != row2){
        return NULL;
    }
    Matrix * pC = (Matrix *) malloc(sizeof(Matrix) );
    pC->row = row1;
    pC->col = col2;
    pC->entry = (float *) aligned_alloc(32 , sizeof(float) * row1 * col2);
    #pragma omp parallel for
    for(size_t i = 0;i < row1;i++){
        size_t j = 0;
        for(j = 0;j + 7 < col2;j += 8){
            __m256 c = _mm256_load_ps(pC->entry + i * col1 + j);
            for(size_t k = 0;k < col1;k++){
                c = _mm256_add_ps(c , _mm256_mul_ps(_mm256_broadcast_ss(pA->entry + i * col1 + k), _mm256_load_ps(pB->entry + k * col2 + j) ) );
            }
            _mm256_store_ps(pC->entry + i * col1 + j , c);
        }
        if(j != col2){
            float * tmp = (float *) aligned_alloc(32, 8 * sizeof(float));
            memset(tmp , 0 , sizeof(tmp) );
            __m256 c = _mm256_load_ps(tmp);
            for(size_t k = 0;k < col1;k++){
                memcpy(tmp , pB->entry + k * col2 + j , (col2 - j) * sizeof(float));
                c = _mm256_add_ps(c , _mm256_mul_ps(_mm256_broadcast_ss(pA->entry + i * col1 + k), _mm256_load_ps(tmp) ) );
            }
            _mm256_store_ps(tmp, c);
            memcpy(pC->entry + i * col1 + j , tmp , (col2 - j) * sizeof(float));
            free(tmp);
        }
    }
    return pC;
}

//block multiplication C += A * B guranted that size of A and B is block_size
inline void do_block(float * C, float * A, float * B, size_t row1, size_t col1, size_t row2, size_t col2, size_t si, size_t sj, size_t sk, size_t block_size){
    for(size_t i = si;i < si + block_size;i++){
        for(size_t j = sj;j < sj + block_size;j += 8){
            __m256 c = _mm256_load_ps(C + i * col1 + j);
            for(size_t k = sk;k < sk + block_size;k++){
                c = _mm256_add_ps(c , _mm256_mul_ps(_mm256_broadcast_ss(A + i * col1 + k), _mm256_load_ps(B + k * col2 + j) ) );
            }
            _mm256_store_ps(C + i * col1 + j , c);
        }
    }
}
//multiply two Matrix A and B in an advanced way using SIMD and openMP and Blocking.
Matrix * matmul_improved_Final(const Matrix * const pA, const Matrix * const pB){
    if(pA == NULL || pB == NULL){
        return NULL;
    }
    size_t row1 = pA->row;
    size_t col1 = pA->col;
    size_t row2 = pB->row;
    size_t col2 = pB->col;
    if(col1 != row2){
        return NULL;
    }
    Matrix * pC = (Matrix *) malloc(sizeof(Matrix) );
    pC->row = row1;
    pC->col = col2;
    pC->entry = (float *) aligned_alloc(32 , sizeof(float) * row1 * col2);
    size_t block_size = 64;
    #pragma omp parallel for
    for(size_t i = 0;i < row1;i += block_size){
        for(size_t j = 0;j < col2;j += block_size){
            for(size_t k = 0;k < col1;k += block_size){
                do_block(pC->entry, pA->entry, pB->entry, row1, col1, row2, col2, i, j, k, block_size);
            }
        }
    }
    return pC;
}