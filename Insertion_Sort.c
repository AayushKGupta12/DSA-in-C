#include<stdio.h>

void printArray(int *A, int n){
    
    for( int i = 0; i< n;i++){
        printf(" %d ",A[i]);
    }
    printf("\n");

}
void insertionSort(int *A, int n){    
    int key;
    for( int i = 1 ; i < n ; i++ ){
        key = A[i];
        int j = i - 1 ; 
        while( key<A[j] && j>=0){
            A[j+1] = A[j];              
            j--;
        }
        A[j+1] = key;
    }
}

int main(){
    int A[] = {12,34,67,23,45,1};
    int n = 6;
    printArray(A,n);
    insertionSort(A,n);
    printArray(A,n);
    return 0;
}