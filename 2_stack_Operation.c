#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }else{
        return 0;
    }
}
int isEmpty(struct stack *ptr){
    if(ptr->top ==-1){
        return 1;
    }else{
        return 0;
    }
}
void push(struct stack *ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow");
    }else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

// last in first out
int pop(struct stack *ptr){
    if(isEmpty(ptr)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
    } else {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int main(){
    // struct stack *sp;  Structure Pointer hai ? structure ka address store karega
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1; // -1 means abhi mera stack khali hai.. kuch nai nhai stack k anadr
    sp->arr=(int *)malloc(sp->size*sizeof(int));
    printf("Stack has been created Successfully\n");
    //printf("%d",isEmpty(sp));
    //printf("%d",isFull(sp));
    push(sp,3);
    push(sp,6);
    push(sp,8);
    push(sp,9);
    push(sp,10);
    push(sp,12);
    printf("Popped %d from the stack\n",pop(sp)); // --> last in first out
    return 0;
}