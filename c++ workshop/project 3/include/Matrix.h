#ifndef _Matrix_H
#define _Matrix_H

typedef struct Matrix{
    int row;              //row number
    int col;              //column number
    float * entry;        //store all entries in wich entry[(i - 1)* col + (j - 1)] is entry in (i, j)
    struct Matrix * pNext;//pointer of next Matrix in Matrix linked list containing all Matrix
} Matrix;
//the head of Matrix linked list
Matrix * pFirstMatrix;
//create new matrix and return the pointer
Matrix * createMatrix(const int row, const int col, const float * const entry);
//check if Matrix exist return true IFF Matrix exists
bool existMatrix(const Matrix * const pMatrix);
//delete Matrix pointed by pointer return true IFF success
bool deleteMatrix(Matrix * const pMatrix);
//copy the data from source Matrix to destination Matrix return true IFF success
bool copyMatrix(Matrix * const dest, const Matrix * const src);
//add tow Matrix return new Matrix pointer ; return NULL IFF sizes of two matrix do not match or Matrix do not exist
Matrix * addMatrix(const Matrix * const pAugend, const Matrix * const pAddend);
//subtract tow Matrix and return new Matrix pointer ; return NULL IFF sizes of two matrix do not match or Matrix do not exist
Matrix * subtractMatrix(const Matrix * const  pMinuend, const Matrix * const pSubtrahend);
//add scalar to a Matrix return new Matrix; return NULL IFF Matrix do not exist
Matrix * addScalarToMatrix(const Matrix * const pMatrix, const float scalar);
//subtract scalar from a Matrix return new Matrix; return NULL IFF Matrix do not exist
Matrix * subtractScalarFromMatrix(const Matrix * const pMatrix, const float scalar);
//multiply Matrix with scalar and return new Matrix; return NULL IFF Matrix do not exist
Matrix * multiplyMatrixWithScalar(const Matrix * const pMatrix, const float scalar);
//multiply two Matrix and return new Matrix; return NULL IFF sizes of two matrix do not match or Matrix do not exist
Matrix * multiplyMatrix(const Matrix * const pA, const Matrix * const pB);
//Find the position of max value of Matrix as (rowIndex - 1) * MatrixColumnNumber + (columnIndex - 1) form; return 0 IFF Matrix do not exist
int MaxValuePositionOfMatrix(const Matrix * const pMatrix);
//Find the position of min value of Matrix as (rowIndex - 1) * MatrixColumnNumber + (columnIndex - 1) form; return 0 IFF Matrix do not exist
int MinValuePositionOfMatrix(const Matrix * const pMatrix);
//print Matrix in bash IFF Matrix exist
void printMatrix(const Matrix * const pMatrix);
//return the transpose of Matrix ; return NULL IFF Matrix do NOT exist
Matrix * transposeMatrix(const Matrix * const pMatrix);
//return standard Matrix
Matrix * standardMatrix(const int size, const float val);
//return Gussian Elimination of Matrix ; return NULL IFF Matrix do NOT exist or size do NOT match
Matrix * gussianEliminationMatrix(const Matrix * const pMatrix);
//get the rank of Matrix
int rankOfMatrix(const Matrix * const pMatrix);
//return attached Matrix from two Matrix like A B then A|B ; return -1 IFF Matrix do NOT exist or size do NOT match
Matrix * attachMatrix(const Matrix * const pA, const Matrix * const pB);
//return the inverse of Matrix; return NULL IFF Matrix do NOT exist or Matrix is NOT a square Matrix
Matrix * inverseMatrix(const Matrix * const pMatrix);

#endif