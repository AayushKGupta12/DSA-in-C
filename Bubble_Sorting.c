#include<stdio.h>
void printArray(int *A, int n){
    for( int i = 0 ; i<n ; i++){
        printf(" %d ",A[i]);
    }
    printf("\n");
}
 
void bubbleSort(int *A, int n){
    for(int i = 0 ; i < n-1 ; i++ ){
        for( int j = 0 ; j < n-1-i ; j++ ){
            if(A[j] > A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main(){
    int A[] = {12,45,57,87,34,22,3};
    int n = 7;
    printArray(A,n);
    bubbleSort(A,n);
    printArray(A,n);
    return 0;
}