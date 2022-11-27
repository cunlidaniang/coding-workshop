#ifndef _Matrix_H
#define _Matrix_H

typedef struct Matrix{
    size_t row;              //row number
    size_t col;              //column number
    float * entry;        //store all entries in wich entry[(i - 1)* col + (j - 1)] is entry in (i, j)
} Matrix;

//creat a matrix with row rows and col columns and random entry values.
Matrix * create_matrix(const size_t row, const size_t col);
//delete a matrix.
void delete_matrix(Matrix * p);
//print Matrix in bash.
void print_matrix(const Matrix * const pMatrix);
//multiply two Matrix A and B in an plain way using several loops.
Matrix * matmul_plain(const Matrix * const pA, const Matrix * const pB);
//multiply two Matrix A and B in an advanced way using SIMD and openMP.
Matrix * matmul_improved(const Matrix * const pA, const Matrix * const pB);
//block multiplication C += A * B
void do_block(float * C, float * A, float * B, size_t row1, size_t col1, size_t row2, size_t col2, size_t si, size_t sj, size_t sk);
//multiply two Matrix A and B in an advanced way using SIMD and openMP and Blocking.
Matrix * matmul_improved_Final(const Matrix * const pA, const Matrix * const pB);


#endif