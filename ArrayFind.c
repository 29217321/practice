#include<stdio.h>
#include<stdlib.h>

/*Search a num in a A[m][n] Array 
 * Each line of the array is increase from left to right
 * Each colum of the array is increase from top to down
 * */
#define N 5

void search(int **A, int num) {
  int i=0, j=0;
  int startRow = 0,startCol = 4;
  int nodeVal = A[startRow][startCol];
  
  if(!A) {
    printf("Error Msg");
    return;
  }
  
  for(i=startRow,j=startCol; j>=0 && i < N;) {
    nodeVal = A[i][j];
    if(num < nodeVal) {
      j--;
    } else if(num == nodeVal) {
      printf("%d %d", i,j);
      return;
    } else { //num > nodeVal
      i++;
    }
  }
}

int main(void) {
  int A[N][N] = {{1,2,4,7,10},
                 {2,3,5,8,11},
                 {4,5,8,9,12},
                 {6,9,10,11,13},
                 {9,10,11,12,14}};
  int *pA[5] = {A[0], A[1], A[2], A[3], A[4]};
  int num;
  scanf("%d", &num);
  search(pA,num);
  return 0;
}
