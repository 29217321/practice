#include<stdio.h>
#include<stdlib.h>

typedef struct linkNode {
    int nodeVal;
    struct linkNode *pNext;
    struct linkNode *pPre;
} LinkNode;

int main(void) {

    LinkNode *pHead;

    pHead = (LinkNode*) malloc(1 * sizeof(LinkNode));
    pHead->nodeVal = 1;
    pHead->pNext = 0x0;
    pHead->pPre = pHead;

    printf("%4d", pHead->nodeVal);

    return 0;
}
