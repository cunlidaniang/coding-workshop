#include<stdio.h>
#include<stdlib.h>
#include <immintrin.h>
#include <omp.h>
#include <sys/time.h>
#include <iostream>
#include <memory>
using namespace std;

class Matrix{
    public:
    shared_ptr<float[]> ptr;
    size_t row , col;
    Matrix(size_t row = 0, size_t col = 0){
        this->row = row;
        this->col = col;
        ptr = shared_ptr<float[]>(new float[row * col]);
        for(size_t i = 0;i < row * col; i++){
            ptr[i] = i;
        }
    }
    Matrix(const Matrix & o){
        this->ptr = o.ptr;
        this->row = o.row;
        this->col = o.col;
    }
    Matrix operator + (const Matrix & o){
        Matrix ans;
        ans.col = o.col;
        ans.row = o.row;
        ans.ptr = shared_ptr<float[]>(new float[row * col]);
        for(size_t i = 0;i < ans.row * ans.col; i++){
            ans.ptr[i] = this->ptr[i] + o.ptr[i];
        }
        return ans;
    }
    Matrix operator * (const float & f){
        Matrix ans;
        ans.col = col;
        ans.row = row;
        ans.ptr = shared_ptr<float[]>(new float[row * col]);
        for(size_t i = 0;i < ans.row * ans.col; i++){
            ans.ptr[i] = this->ptr[i] * f;
        }
        return ans;
    }
    void print(){
        for(size_t i = 0;i < row; i++){
            for(size_t j = 0;j < col; j++){
                cout<< ptr[i * col + j] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Matrix a(3, 4);
    Matrix b(3, 4);
    Matrix c = a + b;
    b = b * 3.0f;
    a.print();
    b.print();
    c.print();
}