#include<stdio.h>
#include<stdlib.h>

int main(void) {
    int *pSteps=0;
    int len;
    int i=0, j=0;

    int **pPath = 0;
    int stepCount = 0;

    printf("input how many numbers: ");
    scanf("%d",&len);
    pSteps = (int *) malloc(len * sizeof(int));

    printf ("input numbers: ");
    while (i < len) {
        scanf("%d", &(pSteps[i]));
        i++;
    }

    printf("\nLength %d\n",len);

    pPath = (int **) malloc (len * sizeof (int *));
    int maxStepCnt = 0;

    for (i=0; i< len; i++) {
        stepCount = pSteps[i]; // how many max steps of current position
        if(stepCount > maxStepCnt) maxStepCnt = stepCount;
        pPath[i] = (int *) malloc (stepCount * sizeof (int));
        printf("Position %d: ", i);
        for(j=1;j <= stepCount; j++) {
            pPath[i][j-1] = j;
            printf("%d ", pPath[i][j-1]);
        }
        printf ("\n");
    }

    //a array to store the good path

    int *goodPath = (int *) malloc(len);
    int goodPathLen = 0;

    int **turnPath = (int **)malloc(maxStepCnt * sizeof(int *));
    for(i=0;i<maxStepCnt;i++) {
        turnPath[i] = (int *) malloc(len * sizeof(int));
    }

    int row, col;
    for(row=0,col=len-1; col>=0; col--,row++) {
        for(int j=0; j<col; j++) {
            turnPath[j][col] = pPath[row][j];
            printf("%d ", turnPath[j][col]);
        }
        printf("\n");
    }

    return 0;
}

