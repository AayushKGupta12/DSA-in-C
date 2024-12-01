#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
int isFull(struct stack* ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }else{
        return 0;
    }
}
int isEmpty(struct stack* ptr){
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
int peek(struct stack* sp, int position) {
    // Check if the stack is empty or position is invalid
    if (position <= 0 || position > sp->top + 1) {
        printf("Invalid position for the stack\n");
        return -1;  // Return -1 to indicate error
    }

    // Return the element at the given position from the top
    return sp->arr[sp->top - position + 1];
}
// somemore stack function

int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
int stackBottom(struct stack* sp){
    return sp->arr[0];

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
    for(int j=1; j<sp->top+1;j++){
        printf("The value at position %d is %d\n",j, peek(sp,j));
    }
    printf("The topmost value of this stack is %d\n",stackTop(sp));
    printf("The Bottom most value of this stack is %d\n",stackBottom(sp));
    //free the dynamically allocated memory, to prevent memory leaks
    free(sp->arr);
    free(sp);
    return 0;
}