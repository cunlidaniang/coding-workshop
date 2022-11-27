// some parameters and includes
#ifndef _HEAD_H
#define _HEAD_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include <sys/time.h>
#include <immintrin.h>
#include <omp.h>
typedef long long ll;
typedef unsigned long long ull;
#define BLOCKSIZE_ROW 8
#define BOLCKSIZE_COL 8
#define BOLCKSIZE_TOG 8

#define For(i, a, b) for(int i = (a);i <= (b);i++)
#define Ford(i, a, b) for(int i = (a);i >= (b);i--)

#endif
