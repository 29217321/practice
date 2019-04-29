#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define SZ 20

typedef struct Stack {
    int* data;
    int size;
}stack;

void InitStack(stack* s) {
    int* data = (int *) malloc(SZ * sizeof(int));
    if(data == NULL) {
        assert(0);
        return;
    }
    s->data = data;
    s->size = 0;
}

void PushStack(stack* s, int num) {
    assert(s);
    if(s->size > SZ) {
        printf("PushStack Failed as stack size is overflow!\n");
        return;
    } else {
        s->data[s->size++] = num;
    }
}

int PopStack(stack* s) {
    assert(s);
    if(s->size < 1) {
        printf("PopStack failed as stack is NULL!\n");
        return -1;
    } else {
        int val = s->data[s->size-1];
        s->size--;
        return val;
    }
}

int TopStack(stack* s) {
    assert(s);
    return s->data[s->size-1];
}

int EmptyStack(stack* s) {
    assert(s);
    return s->size == 0;
}

void PrintStack(stack* s) {
    assert(s);
    for (int i=0; i<s->size; i++) {
        printf("%4d", s->data[i]);
    }
    printf("\n");
}

int main(void) {
    stack s;
    stack* ps = &s;

    InitStack(ps);
    for (int i = 0; i < SZ; i++) {
        PushStack(ps, i);
    }

    PrintStack(ps);

    int size = ps->size;
    for (int j=0; j<size; j++) {
        int val = PopStack(ps);
        printf("%4d", val);
    }

    return 0;
}




