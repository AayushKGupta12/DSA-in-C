#include <stdio.h>

void printArray(int *A, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void partition(int l. int h){
    int pivot = a[l];
    int i = l;
    int j = h;
    while(i<j){
        while(a[i] <= pivot){
            i++;
        }
        while(a[j] > pivot){
            j--
        }
        if( i < j){
            swap(a,i,j)
        }
    }
    swap(a,j,l);
    return j;
}




void quickSort(int *A, int low, int high) {
    if(low < high){
        int partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1); // sort left subarray
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}

int main() {
    int A[] = {3, 5, 2, 13, 12};
    int n = sizeof(A) / sizeof(A[0]);
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}
