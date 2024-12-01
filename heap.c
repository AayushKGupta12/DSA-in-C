#include<stdio.h>
#define MAX 100
int heap[MAX];
int heap_size = 0;

void swap(int*x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//max - heapify function to maintina max - heap property
void maxheapify(int i){
    int largest = i;
    int left = 2* i+1;
    int right = 2* i +2;
    if( left < heap_size && heap[left] > heap [largest]){
        largest = left;
    }
    if( right < heap_size && heap[right] > heap[largest]){
        largest = right;
    }
    if(largest != i){
        swap(&heap[i],&heap[largest]);
        maxheapify(largest);
    }
}

void buildMaxHeap(int arr[], int n){
    int i;
    heap_size = n;
    for( i = 0; i< n; i++){
        heap[i] = arr[i];
    }

    for( i =(n/2)-1; i>=0; i--){
        maxheapify(i);
    }
}

void insert( int value){
    int i;
    if( heap_size == MAX){
        printf("Heap is FULL !! ");
        return;
    }
    heap_size++;
    i=heap_size - 1;
    heap[i] = value;

    while(( i != 0 ) && heap[(i - 1)/2 < heap[i]]){
        swap(&heap[i],&heap[(i-1)/2]);
        i=(i-1)/2;
    }
}

void deleteMax(){
    if( heap_size <= 0){
        printf("Heap is Empty");
        return;
    }

    heap[0] = heap[heap_size - 1];
    heap_size--;
    maxheapify(0);
}

void printHeap(){
    int i;
    for( i = 0; i<heap_size; i++){
        printf(" %d ",heap[i]);
    }
    printf("\n");
}

void heapsort(arr,n){
    buildMaxHeap(arr,n);
    for(int i = heap_size ; i>=1 ; --i){
        swap(arr[0],arr[1]);
        heap_size = heap_size - 1;
        maxheapify(arr,0);
    }
}

int main(){
    int n;
    int arr[] ={20,15,30,8,10,50,16};
    n = sizeof(arr)/sizeof(arr[0]);

    buildMaxHeap(arr,n);

    printf("Max- heap after building from array");
    printHeap();

    printf("Inserting 25 into the heap\n");
    insert(25);

    printf("heap after insertion: ");
    printHeap();

    printf("Deleting max element....\n");
    deleteMax();
    printf("Heap after deletion: ");
    printHeap();

    heapsort(arr,n);
    return 0;
}