#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack structure definition
struct stack {
    int size;
    int top;
    char *arr;
};

// Function to check if the stack is empty
int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

// Function to check if the stack is full
int isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

// Function to push an element onto the stack
void push(struct stack *ptr, char val) {
    if (isFull(ptr)) {
        printf("Stack Overflow\n");
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

// Function to pop an element from the stack
char pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return '\0'; // Returning null character for empty stack
    } else {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// Function to get the top element of the stack without popping it
char stackTop(struct stack *ptr) {
    return ptr->arr[ptr->top];
}

// Function to check the precedence of operators
int precedence(char ch) {
    if (ch == '*' || ch == '/') {
        return 3;
    } else if (ch == '+' || ch == '-') {
        return 2;
    } else {
        return 0;
    }
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to convert infix expression to postfix expression
char *infixToPostfix(char *infix) {
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;  // Track infix traversal
    int j = 0;  // Track postfix addition
    
    while (infix[i] != '\0'){
        if (!isOperator(infix[i])) {  // If it's an operand
            postfix[j] = infix[i];
            j++;
            i++;
        } else {  // If it's an operator
            while (!isEmpty(sp) && precedence(infix[i]) <= precedence(stackTop(sp))) {
                postfix[j] = pop(sp);
                j++;
            }
            push(sp, infix[i]);
            i++;
        }
    }
    
    // Pop remaining operators from the stack
    while (!isEmpty(sp)) {
        postfix[j] = pop(sp);
        j++;
    }
    
    postfix[j] = '\0';  // Null-terminate the postfix expression
    return postfix;
}

int main() {
    char infix[] = "A*(B-C)*D";
    printf("Postfix is: %s\n", infixToPostfix(infix));
    return 0;
}
