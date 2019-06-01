#include<iostream>
#include<string.h>
#include<vector>
#include<list>
#include<map>
#include<stack>
#include<set>

using namespace std;

const int MAX_SIZE = 10;
int heap[MAX_SIZE];

//heap was starting from index 1 instead of 0
void max_heap_insert(int *heap, int *n, int item) {
    int cur, parent;

    if((*n) == MAX_SIZE) {//full
        cout << "Heap is full";
        return;
    }

    cur = ++(*n);
    parent = cur/2; //parent node location
    while ((cur != 1) && (item > heap[parent])) {
        //if heap is not blank and the item is bigger than parent
        heap[cur] = heap[parent];
        cur = parent;
        parent /=2;
    }

    heap[cur] = item;
}

int max_heap_delete(int *heap, int *n) {
    int item, temp;
    int child, parent;

    if(*n == 0) { //heap is blank
        cout << "Error of delete blank heap";
        return -1;
    }

    item=heap[1]; //max number
    temp = heap[(*n)--]; //the last item of the heap
    parent = 1;//initial parent is starting from index 1
    child = parent * 2;

    while (child <= (*n)) { //iterate the heap
        if((child < *n) && heap[child] < heap[child+1]) {
            child++; //the max number of the heap
        }
        if(temp >= heap[child]) break; // compare with the last one
        else {
            heap[parent] = heap[child];
            parent=child;
            child *=2;
        }
    }
    heap[parent] = temp;
    return item; //return the delete one
}

void printHeap(int *heap, int size) {
    for(int i=0; i<size; i++) {
        cout << heap[i];
    }
    cout << endl;
}

int main(void) {

    int num;
    int cnt = 0;
    cout << "input " << MAX_SIZE << " numbers for a heap:" << endl;

    for(int i=1;i<MAX_SIZE;i++) {
        cin >> num;
        max_heap_insert(heap, &cnt, num);
    }
    printHeap(heap, cnt);

    num = max_heap_delete(heap, &cnt);
    printHeap(heap, cnt);

    return 0;
}
