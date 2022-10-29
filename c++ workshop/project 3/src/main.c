#include"head.h"
#include"Matrix.h"

int main(){
    float a[12] = {1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1};
    Matrix * pa = createMatrix(3 , 3, a);
    Matrix * pb = createMatrix(3 , 3, a);
    Matrix * pc = gussianEliminationMatrix(pa);
    Matrix * pd = transposeMatrix(pc);
    printMatrix(pa);
    printf("\n");
    printMatrix(pb);
    printf("\n");
    printMatrix(pc);
    printf("\n");
    printMatrix(pd);
    printf("\n");
    printf("%d\n", rankOfMatrix(pa) );
    printf("%d\n", rankOfMatrix(pb) );
    printf("%d\n", rankOfMatrix(pc) );
    printf("%d\n", rankOfMatrix(pd) );
}