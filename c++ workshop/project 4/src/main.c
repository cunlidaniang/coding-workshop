#include"head.h"
#include"Matrix.h"

#define TIME_START gettimeofday(&t1, NULL);
#define TIME_END(NAME) gettimeofday(&t2, NULL); \
             printf(NAME);\
             usetime_ms = (t2.tv_sec - t1.tv_sec) * 1000  + (double)(t2.tv_usec - t1.tv_usec) / 1000; \
             printf("time = %lf ms\n", usetime_ms);

int main(){
    while(true){
        int n;
        scanf("%d", &n);
        if(n > 70000){
            printf("too large\n");
            continue;
        }
        Matrix * a = create_matrix(n, n);
        // print_matrix(a);
        // printf("\n");
        struct timeval t1,t2;
        double usetime_ms;
        // TIME_START;
        // Matrix * b = matmul_plain(a, a);
        // TIME_END("plain");
        // print_matrix(b);
        // printf("\n");
        TIME_START;
        Matrix * c = matmul_improved_Final(a, a);
        TIME_END("advanced");
        // print_matrix(c);
        // printf("\n");
        delete_matrix(a);
        // delete_matrix(b);
        delete_matrix(c);
    }
}