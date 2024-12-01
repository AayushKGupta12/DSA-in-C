#include<stdio.h> 
#include<stdlib.h>

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

//code for deletion
int indDeletion(int arr[],int element,int index, int capacity,int size){
    if(index>=capacity){
        printf("Index is empty, Sorry u cant delete anything");
        return -1;
    }
    for(int i=index;i<=size-1;i++){
        arr[i]=arr[i+1];
    }
}

int main(){
    int capacity=100;
    int arr[100]={7,8,12,27,88};
    printf("Array before deletion is : \n");
    display(arr,5);
    int size=5, element=27, index=3;
    indDeletion(arr,element,index,capacity,size);
    size =-1 ;
    printf("Array After deletion is : \n");
    display(arr,5);
    return 0;
}