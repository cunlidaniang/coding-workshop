#include"head.h"
#include"Matrix.h"

#define P 1e-5
//the head of Matrix linked list
Matrix * pFirstMatrix = NULL;
//create new matrix and return the pointer //if entry == NULL then all 0
Matrix * createMatrix(const int row, const int col, const float * const entry){
    if(row <= 0 || col <= 0){ //if input in valid return NULL
        return NULL;
    }
    Matrix * pNew = (Matrix *) malloc(sizeof(Matrix) );
    pNew->row = row;
    pNew->col = col;
    int size = row * col;
    pNew->entry = (float *) malloc(sizeof(float) * size);
    if(entry == NULL){
        memset(pNew->entry, 0, sizeof(float) * size);
    }else{
        memcpy(pNew->entry, entry, sizeof(float) * size);
    }
    pNew->pNext = pFirstMatrix;
    pFirstMatrix = pNew;
    return pNew;
}
//check if Matrix exist return true IFF Matrix exists
bool existMatrix(const Matrix * const pMatrix){
    if(pMatrix == NULL){
        return false;
    }
    Matrix * pTmp = pFirstMatrix;
    while(pTmp!= NULL){
        if(pTmp == pMatrix){
            return true;
        }
        pTmp = pTmp->pNext;
    }
    return false;
}
//delete Matrix pointed by pointer return true IFF success
bool deleteMatrix(Matrix * const pMatrix){
    //is NULL
    if(pMatrix == NULL){
        return false;
    }
    //is pFirstMatrix
    if(pMatrix == pFirstMatrix){
        pFirstMatrix = pFirstMatrix->pNext;
        free(pMatrix->entry);
        free(pMatrix);
        return true;
    }
    //if pTmp in linked list
    Matrix * pTmp = pFirstMatrix;
    while(pTmp!= NULL){
        if(pTmp->pNext == pMatrix){
            pTmp->pNext = pMatrix->pNext;
            free(pMatrix->entry);
            free(pMatrix);
            return true;
        }
        pTmp = pTmp->pNext;
    }
    return false;
}
//copy the data from source Matrix to destination Matrix return true IFF success
bool copyMatrix(Matrix * const dest, const Matrix * const src){
    //if dest == src
    if(dest == src){
        return false;
    }
    //if not all exist
    if(!existMatrix(dest) || !existMatrix(src) ){
        return false;
    }
    dest->row = src->row;
    dest->col = src->col;
    int size = src->row * src->col;
    free(dest->entry);
    dest->entry = malloc(sizeof(float) * size);
    memcpy(dest->entry, src->entry, sizeof(float) * size);
    return true;
}
//add tow Matrix return new Matrix pointer ; return NULL IFF sizes of two matrix do not match or Matrix do not exist
Matrix * addMatrix(const Matrix * const pAugend, const Matrix * const pAddend){
    if(!existMatrix(pAugend) || !existMatrix(pAddend) ){
        return NULL;
    }
    if(pAugend->row != pAddend->row || pAugend->col != pAddend->col){
        return false;
    }
    Matrix * ans = createMatrix(pAugend->row, pAugend->col, NULL);
    For(i, 1, ans->row){
        For(j, 1, ans->col){
            int pos = (i - 1)* ans->col + (j - 1);
            ans->entry[pos] = pAugend->entry[pos] + pAddend->entry[pos];
        }
    }
    return ans;
}
//subtract tow Matrix and return new Matrix pointer ; return NULL IFF sizes of two matrix do not match or Matrix do not exist
Matrix * subtractMatrix(const Matrix * const  pMinuend, const Matrix * const pSubtrahend){
    if(!existMatrix(pMinuend) || !existMatrix(pSubtrahend) ){
        return NULL;
    }
    if(pMinuend->row != pSubtrahend->row || pMinuend->col != pSubtrahend->col){
        return false;
    }
    Matrix * ans = createMatrix(pMinuend->row, pMinuend->col, NULL);
    For(i, 1, ans->row){
        For(j, 1, ans->col){
            int pos = (i - 1)* ans->col + (j - 1);
            ans->entry[pos] = pMinuend->entry[pos] - pSubtrahend->entry[pos];
        }
    }
    return ans;
}
//add scalar to a Matrix return new Matrix; return NULL IFF Matrix do not exist
Matrix * addScalarToMatrix(const Matrix * const pMatrix, const float scalar){
    if(!existMatrix(pMatrix) ){
        return NULL;
    }
    Matrix * ans = createMatrix(1, 1, NULL);
    copyMatrix(ans, pMatrix);
    For(i, 1, ans->row){
        For(j, 1, ans->row){
            int pos = (i - 1) * ans-> col + (j - 1);
            ans->entry[pos] += scalar;
        }
    }
    return ans;
}
//subtract scalar from a Matrix return new Matrix; return NULL IFF Matrix do not exist
Matrix * subtractScalarFromMatrix(const Matrix * const pMatrix, const float scalar){
    return addScalarToMatrix(pMatrix, -scalar);
}
//multiply Matrix with scalar and return new Matrix; return NULL IFF Matrix do not exist
Matrix * multiplyMatrixWithScalar(const Matrix * const pMatrix, const float scalar){
    if(!existMatrix(pMatrix) ){
        return NULL;
    }
    Matrix * ans = createMatrix(1, 1, NULL);
    copyMatrix(ans, pMatrix);
    For(i, 1, ans->row){
        For(j, 1, ans->row){
            int pos = (i - 1) * ans-> col + (j - 1);
            ans->entry[pos] *= scalar;
        }
    }
    return ans;
}
//multiply two Matrix and return new Matrix; return NULL IFF sizes of two matrix do not match or Matrix do not exist
Matrix * multiplyMatrix(const Matrix * const pA, const Matrix * const pB){
    if(!existMatrix(pA) || !existMatrix(pB) ){
        return NULL;
    }
    if(pA->col != pB->row){
        return NULL;
    }
    Matrix * ans = createMatrix(pA->row, pB->col, NULL);
    For(i, 1, ans->row){
        For(j, 1, ans->col){
            For(k, 1, pA->col){
                ans->entry[(i - 1) * ans->col + (j - 1)] += pA->entry[(i - 1) * pA->col + (k - 1)] * pB->entry[(k - 1) * pB->col + (j - 1)];
            }
        }
    }
    return ans;
}
//Find the position of max value of Matrix as (rowIndex - 1) * MatrixColumnNumber + (columnIndex - 1) form; return 0 IFF Matrix do not exist
int MaxValuePositionOfMatrix(const Matrix * const pMatrix){
    if(!existMatrix(pMatrix) ){
        return -1;
    }
    int ansPos = 0;
    For(i, 1, pMatrix->row){
        For(j, 1, pMatrix->col){
            int pos = (i - 1) * pMatrix->col + (j - 1);
            int val = pMatrix->entry[pos];
            if(val > pMatrix->entry[ansPos]){
                ansPos = pos;
            }
        }
    }
    return ansPos;
}
//Find the position of min value of Matrix as (rowIndex - 1) * MatrixColumnNumber + (columnIndex - 1) form; return 0 IFF Matrix do not exist
int MinValuePositionOfMatrix(const Matrix * const pMatrix){
    if(!existMatrix(pMatrix) ){
        return -1;
    }
    int ansPos = 0;
    For(i, 1, pMatrix->row){
        For(j, 1, pMatrix->col){
            int pos = (i - 1) * pMatrix->col + (j - 1);
            int val = pMatrix->entry[pos];
            if(val < pMatrix->entry[ansPos]){
                ansPos = pos;
            }
        }
    }
    return ansPos;
}
//print Matrix in bash IFF Matrix exist
void printMatrix(const Matrix * const pMatrix){
    if(!existMatrix(pMatrix) ){
        return;
    }
    For(i, 1, pMatrix->row){
        For(j, 1, pMatrix->col){
            printf("%f", pMatrix->entry[(i - 1) * pMatrix->col + (j - 1)]);
        }
        printf("\n");
    }
}
//return the transpose of Matrix ; return NULL IFF Matrix do NOT exist
Matrix * transposeMatrix(const Matrix * const pMatrix){
    if(!existMatrix(pMatrix) ){
        return NULL;
    }
    Matrix * ans = createMatrix(pMatrix->col, pMatrix->row, NULL);
    For(i, 1, ans->row){
        For(j, 1, ans->col){
            ans->entry[(i - 1)* ans->col + (j - 1)] = pMatrix->entry[(j - 1)* ans->row + (i - 1)];
        }
    }
    return ans;
}
//return standard Matrix
Matrix * standardMatrix(const int size, const float val){
    Matrix * ans = createMatrix(size, size, NULL);
    For(i, 1, size){
        ans->entry[(i - 1)* size + (i - 1)] = val;
    }
    return ans;
}
//return Gussian Elimination of Matrix ; return NULL IFF Matrix do NOT exist or size do NOT match
Matrix * gussianEliminationMatrix(const Matrix * const pMatrix){
    if(!existMatrix(pMatrix) ){
        return NULL;
    }
    Matrix * ans = createMatrix(1, 1, NULL);
    copyMatrix(ans, pMatrix);

    int lines = 0;
    For(i, 1, ans->col){
        lines++;
        if(lines >= ans->row){
            break;
        }
        int tmp = 0;
        For(j, lines, ans->row){
            if(abs(ans->entry[(j - 1) * ans->col + (i - 1)]) > P){
                tmp = j;
                break;
            }
        }
        if(tmp == 0){
            lines--;
            continue;
        }
        For(j, i, ans->col){
            float tmpVal = ans->entry[(lines - 1) * ans->col + (j - 1)];
            ans->entry[(lines - 1) * ans->col + (j - 1)] = ans->entry[(tmp - 1) * ans->col + (j - 1)];
            ans->entry[(tmp - 1) * ans->col + (j - 1)] = tmpVal;
        }
        For(j, lines + 1, ans->row){
            if(abs(ans->entry[(j - 1)* ans->col + (i - 1)]) > P){
                float b = ans->entry[(j - 1)* ans->col + (i - 1)] / ans->entry[(lines - 1)* ans->col + (i - 1)];
                For(k, i, ans->col){
                    ans->entry[(j - 1)* ans->col + (k - 1)] -= b * ans->entry[(lines - 1)* ans->col + (k - 1)];
                }
            }
        }
    }
    return ans;
}
//get the rank of Matrix
int rankOfMatrix(const Matrix * const pMatrix){
    Matrix * tmp = gussianEliminationMatrix(pMatrix);
    if(tmp == NULL){
        return -1;
    }
    int ans = 0;
    For(i, 1, tmp->row){
        For(j, 1, tmp->col){
            if(abs(tmp->entry[(i - 1)* tmp->col + (j - 1)] ) > P ){
                ans++;
                break;
            }
        }
    }
    deleteMatrix(tmp);
    return ans;
}
//return attached Matrix from two Matrix like A B then A|B ; return -1 IFF Matrix do NOT exist or size do NOT match
Matrix * attachMatrix(const Matrix * const pA, const Matrix * const pB){
    if(!existMatrix(pA) || !existMatrix(pB) ){
        return NULL;
    }
    if(pA->row != pB->row){
        return NULL;
    }
    Matrix * ans = createMatrix(pA->row, pA->col + pB->col, NULL);
    For(i, 1, pA->row){
        For(j, 1, pA->col){
            ans->entry[(i - 1)* ans->col + (j - 1)] = pA->entry[(i - 1) * pA->col + (j - 1)];
        }
    }
    For(i, 1, pB->row){
        For(j, 1, pB->col){
            ans->entry[(i - 1)* ans->col + (pA->col+ j - 1)] = pB->entry[(i - 1) * pB->col + (j - 1)];
        }
    }
    return ans;
}
//return the inverse of Matrix; return NULL IFF Matrix do NOT exist or Matrix is NOT a square Matrix
Matrix * inverseMatrix(const Matrix * const pMatrix){
    if(!existMatrix(pMatrix) ){
        return NULL;
    }
    if(pMatrix->row != pMatrix->col){
        return NULL;
    }
    if(rankOfMatrix(pMatrix) != pMatrix->row ){
        return NULL;
    }
    Matrix * I = standardMatrix(pMatrix->row, 1);
    Matrix * AB = attachMatrix(pMatrix, I);
    deleteMatrix(I);
    Matrix * TMP = gussianEliminationMatrix(AB);
    deleteMatrix(AB);
    AB = TMP;
    Ford(i, AB->row, 1){
        Ford(j, AB->col, i){
            AB->entry[(i - 1)* AB->col + (j - 1)]/= AB->entry[(i - 1)* AB->col + (i - 1)];
        }
        For(j, 1, i - 1){
            if(abs(AB->entry[(j - 1) * AB->col + (i - 1)]) > P ){
                float b = AB->entry[(j - 1)* AB->col + (i - 1)];
                For(k, i, AB->col){
                    AB->entry[(j - 1)* AB->col + (k - 1)] -= b * AB->entry[(i - 1)* AB->col + (k - 1)];
                }
            }
        }
    }
    Matrix * ans = createMatrix(pMatrix->row, pMatrix->col, NULL);
    For(i, 1, ans->row){
        For(j, 1, ans->col){
            ans->entry[(i - 1) * ans->col + (j - 1)] = AB->entry[(i - 1) * AB->col + (ans->col + j - 1)];
        }
    }
    deleteMatrix(AB);
    return ans;
}