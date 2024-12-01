#include<stdio.h>
void display(int arr[], int n){
    //traversal code
    for(int i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
    printf("\n");
}
    // Insertion code 
int indInsertion(int arr[],int size,int element,int capacityArr ,int index){
    if(size>=capacityArr){
        return -1;
    }
    
    for (int i = size-1; i >=index; i--){
        arr[i+1]=arr[i];
    }

    arr[index]=element;
    return 1;

}

int main(){
    int arr[100]={7,12,67,93,27,88};
    printf("The Traversal Arrays is : ");
    int size=10;
    display(arr,size);
    int element=45, capacityArr=100, index=3; 
    printf("The Inserted Array is : \n");
    indInsertion(arr,size,element,capacityArr ,index); 
    size +=1;
    display(arr,size);
    return 0;
}