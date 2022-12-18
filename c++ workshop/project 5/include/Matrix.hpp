#ifndef _Matrix_HPP
#define _Matrix_HPP

#include"head.hpp"

template<typename T>
class Matrix{
    private:
    size_t row;           //row number
    size_t col;           //column number
    shared_ptr<T *> entry;//store all entries in wich entry[(i - 1)* step + (j - 1)] is entry in (i, j)
    size_t step;          //step length

    public:
    Matrix() = delete;

    Matrix(size_t row, size_t col):row(row), col(col), step(col){
        entry = make_shared<T *>( (T *) malloc(col * row * sizeof(T) ) );
    }

    bool operator == (const Matrix & o){
        if(*this == o){
            return true;
        }
        if(col != o.col || row != o.row){
            return false;
        }
        for(size_t i = 0;i< row;i++){
            for(size_t j = 0;j< col;j++){
                if((*entry)[i * step + j] != (*o.entry)[i * o.step + j]){
                    return false;
                }
            }
        }
        return true;
    }

    Matrix operator + (const Matrix & o){
        Matrix ans(row, col);
        if(row != o.row || col != o.col){
            throw("erro size do not match in +");
        }
        for(size_t i = 0;i< row;i++){
            for(size_t j = 0;j< col;j++){
                (*ans.entry)[i * ans.step + j] = (*entry)[i * step + j] + (*o.entry)[i * o.step + j];
            }
        }
        return ans;
    }

    Matrix operator - (const Matrix & o){
        Matrix ans(row, col);
        if(row != o.row || col != o.col){
            throw("erro size do not match in -");
        }
        for(size_t i = 0;i< row;i++){
            for(size_t j = 0;j< col;j++){
                (*ans.entry)[i * ans.step + j] = (*entry)[i * step + j] - (*o.entry)[i * o.step + j];
            }
        }
        return ans;
    }

    Matrix operator * (const Matrix & o){
        Matrix ans(row, o.col);
        if(col != o.row){
            throw("erro size do not match in *");
        }
        for(size_t i = 0;i< row;i++){
            for(size_t j = 0;j< o.col;j++){
                (*ans.entry)[i * ans.step + j] = 0;
            }
        }
        for(size_t i = 0;i< row;i++){
            for(size_t k = 0;k< col;k++){
                for(size_t j = 0;j< o.col;j++){
                    (*ans.entry)[i * ans.step + j] += (*entry)[i * step + k] * (*o.entry)[k * o.step + j];
                }
            }
        }
        return ans;
    }

    void print(){
        for(size_t i = 0;i< row;i++){
            for(size_t j = 0;j< col;j++){
                cout<< (*entry)[i * step + j] << " ";
            }
            cout<< endl;
        }
    }

    Matrix getROI(size_t prow, size_t pcol, size_t sizeRow, size_t sizeCol){
        Matrix ans(sizeRow, sizeCol);
        ans.entry = make_shared<T *> ((*entry)+ prow * step + pcol);
        return ans;
    }

    T & get(size_t r, size_t c){
        return (*entry)[(r - 1) * step + (c - 1)];
    }

    void set(size_t r, size_t c, T v){
        (*entry)[(r - 1) * step + (c - 1)] = v;
    }

    ~Matrix(){
        entry = nullptr;
    }
};

#endif