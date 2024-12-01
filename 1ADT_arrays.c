#include<stdio.h>
#include<stdlib.h>
struct myArray{
    int total_size;
    int used_size; 
    int *ptr; // array 1st element ko point karega
};
void createArray(struct myArray*a, int tsize, int usize){
    a->total_size=tsize;
    a->used_size=usize;
    a->ptr=(int*)malloc(tsize*sizeof(int));
}
// ek show functiuon create kiya gaya jaha pe for void k anadr for loop laga ke ham logon ne
//loop run kiya 0 se used_size k pointer create tak and with increment of 1
// fir printf k anadr ham logon ne "a->ptr" access the array stored inside "a" and [i] states Ith element
void show(struct myArray *a){
    for(int i = 0;i < a->used_size; i++){
        printf("%d\n",(a->ptr)[i]);
    }
}

void setVal(struct myArray *a){
    int n;
    for(int i=0;i < a->used_size;i++){
        printf("Enter element %d ",i);
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
}

int main(){
    struct myArray marks;
    createArray(&marks,10,2);
    setVal(&marks);
    show(&marks);
    return 0;
}
