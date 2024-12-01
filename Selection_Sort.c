#include<stdio.h>

void printArray(int *A, int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n){
    for(int i = 0 ; i < n-1 ; i++){
        int minidx = A[i];
        for( int j = i+1 ; j < n ; j++ ){
            if(minidx[i] > A[j]){
                
            }
        }
    }
}

int main(){
    int A[]={12,54,65,7,23,9};
    int n=6;
    printArray(A,n);
    selectionSort(A,n);
    printArray(A,n);
    return 0;    
}