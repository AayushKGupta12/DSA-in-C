//Ajj stack padhenge Stack using Array
#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }else{
        return 0;
    }
};

int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }else{
        return 0;
    }
};

void push(struct stack *ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow");
    }else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
    } else {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int paranthesisisMatch(char *exp) {
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++) { //The '\0' at the end marks the end of the string. 
    //The actual array size is 6 to accommodate the five characters of "Hello" and the terminating null character.
        if (exp[i] == '(') {
            push(sp, '(');
        } else if (exp[i] == ')') {
            if (isEmpty(sp)) {
                return 0;
            }
            pop(sp);
        }
    }
    int result = isEmpty(sp);
   
    return result;
}

int main() {
    char *expression = "(1+2*(3/4)";
    if (paranthesisisMatch(expression)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }
    return 0;
}
