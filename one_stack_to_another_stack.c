#include <stdio.h>
#include <stdlib.h>

// Define a stack structure
struct Stack {
    int size;
    int top;
    int* arr;
};

// Function to create a stack
struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (int*)malloc(size * sizeof(int));
    return stack;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (stack->top < stack->size - 1) {
        stack->arr[++stack->top] = value;
    }
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top >= 0) {
        return stack->arr[stack->top--];
    }
    return -1; // Return -1 if stack is empty
}

// Function to display the stack
void display(struct Stack* sp) {
    for (int i = 0; i <= sp->top; i++) {
        printf("%d ", sp->arr[i]);
    }
    printf("\n");
}

// Function to copy elements from one stack to another
void copyStack(struct Stack* source, struct Stack* destination) {
    struct Stack* temp = createStack(source->size); // Temporary stack
    
    // Move elements from source stack to temp stack
    while (source->top >= 0) {
        push(temp, pop(source));
    }

    // Move elements from temp stack to destination stack
    while (temp->top >= 0) {
        int value = pop(temp);
        push(destination, value); // Copy to destination
    }

    free(temp); // Free the temporary stack
}

int main() {
    // Create and initialize the source stack
    struct Stack* source = createStack(5);
    push(source, 10);
    push(source, 20);
    push(source, 30);

    printf("Source Stack: ");
    display(source);

    // Create the destination stack
    struct Stack* destination = createStack(5);

    // Copy elements from source to destination
    copyStack(source, destination);

    printf("Source Stack after copying: ");
    display(source);

    printf("Destination Stack: ");
    display(destination);

    // Free the memory
    free(source->arr);
    free(source);
    free(destination->arr);
    free(destination);

    return 0;
}
