#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Stack structure definition
struct stack {
    int size;
    int top;
    char* arr;
};

// Function to check if the stack is empty
int isEmpty(struct stack* sp) {
    return sp->top == -1;
}

// Function to check if the stack is full
int isFull(struct stack* sp) {
    return sp->top == sp->size - 1;
}

// Function to push an element onto the stack
void push(struct stack* sp, char val) {
    if (!isFull(sp)) {
        sp->arr[++sp->top] = val;
    }
}

// Function to pop an element from the stack
char pop(struct stack* sp) {
    if (!isEmpty(sp)) {
        return sp->arr[sp->top--];
    }
    return '\0'; // Null character if stack is empty
}

// Function to get the top element of the stack without popping it
char stackTop(struct stack* sp) {
    return sp->arr[sp->top];
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

// Function to reverse a string
void reverse(char* exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

// Function to convert infix expression to postfix
char* infixToPostfix(char* infix) {
    struct stack* sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));
    
    char* postfix = (char*)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;  // Track infix traversal
    int j = 0;  // Track postfix addition
    
    while (infix[i] != '\0') {
        if (!isOperator(infix[i]) && infix[i] != '(' && infix[i] != ')') {  // If it's an operand
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {  // If it's a left parenthesis
            push(sp, infix[i++]);
        } else if (infix[i] == ')') {  // If it's a right parenthesis
            while (!isEmpty(sp) && stackTop(sp) != '(') {
                postfix[j++] = pop(sp);
            }
            pop(sp);  // Pop the left parenthesis
            i++;
        } else {  // If it's an operator
            while (!isEmpty(sp) && precedence(infix[i]) <= precedence(stackTop(sp))) {
                postfix[j++] = pop(sp);
            }
            push(sp, infix[i++]);
        }
    }
    
    // Pop remaining operators from the stack
    while (!isEmpty(sp)) {
        postfix[j++] = pop(sp);
    }
    
    postfix[j] = '\0';  // Null-terminate the postfix expression
    return postfix;
}

// Function to convert infix to prefix
char* infixToPrefix(char* infix) {
    // Step 1: Reverse the infix expression
    reverse(infix);
    
    // Step 2: Replace '(' with ')' and vice versa
    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    
    // Step 3: Convert the modified infix expression to postfix
    char* postfix = infixToPostfix(infix);
    
    // Step 4: Reverse the postfix expression to get the prefix
    reverse(postfix);
    return postfix;
}

int main() {
    char infix[] = "A*(B-C)*D";
    printf("Infix Expression: %s\n", infix);
    char* prefix = infixToPrefix(infix);
    printf("Prefix Expression: %s\n", prefix);
    return 0;
}
