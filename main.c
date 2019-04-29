#include<stdio.h>
#define N 20

void bubbleSort(int num[], int len) {
    for(int i=0; i < len; i++) {
        for (int j=i+1; j< len; j++) {
            if(num[i] > num[j]) {
                int tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }

        }
    }
}

/***********************************************************************************************
* to divide the array,in a way that all left numbers are smaller than the value at basePos
* all right numbers are bigger than the value at basePos
* return the Index of the basePos
***********************************************************************************************/
int division(int num[], int left, int right) {

    int baseVal = num[left];

    while(left < right) {
        //start from the right
        while (left < right && num[right] >= baseVal){
            right--;
        }
        //find a value which is smaller than baseVal
        num[left] = num[right];

        //then search from right 
        while (left < right && num[left] <= baseVal) {
            left++;
        }
        //find a value which is bigger than baseVal
        num[right] = num[left];
    }

    //put the baseVal to the postion of num[left]
    num[left] = baseVal;
    //return the postion;
    return left;

}

/***********************************
 *
 *  left: Index of the left starting position
 *  right: Index of the right ending position
 *
 ***********************************/
void quickSort(int num[], int left, int right) {
    if (left >= right) return;
    //left must be smaller than right
    //to divide the array,in a way that all left numbers are smaller than the value at basePos
    //all right numbers are bigger than the value at basePos
    int basePos = division(num, left, right);

    //use the same way to sort the left part of this arry
    quickSort(num, left, basePos-1);
    //use the same way to sort the right part of this array
    quickSort(num, basePos+1, right);
}

void printArray(int num[], int len) {
    for(int i=0; i<len; i++) {
        printf("%4d", num[i]);
    }
    printf("\n");
}

int main(void) {
    int num[N] = {4,19,23,1,89,12,5,7,8,9,71,45,32,58,66,0,99,91,18,100};

    //bubbleSort(num, N);
    quickSort(num, 0, N-1);

    printArray(num, N);
    return 0;
}

