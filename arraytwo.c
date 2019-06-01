#include<stdio.h>
#include<stdlib.h>

void printArray(int **a, int l, int w) {

    for(int i=0;i<l;i++) {
        for(int j=0; j<w; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int orig[4][3] = {{1,  2,  3},
                      {4,  5,  6},
                      {7,  8,  9},
                      {10, 11, 12}};
    int turnArr[3][4] = {};
    int *pOrig[4] = {orig[0], orig[1], orig[2], orig[3]};
    int *pTurnArr[3] = {turnArr[0], turnArr[1], turnArr[2]};

    printArray(pOrig, 4, 3);
    
    printf("\n");

    for(int row=3, col=0; row>=0; row--, col++) {
        for(int k=0; k<3; k++) {
            turnArr[k][col] = orig[row][k];
        }
    }


    printArray(pTurnArr, 3, 4);

    return 0;
}
