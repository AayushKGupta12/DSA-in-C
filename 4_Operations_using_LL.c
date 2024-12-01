#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node *ptr){
    while(ptr!=NULL) {
        printf("Element: %d\n", ptr->data);
        ptr=ptr->next;
    }
}
int isEmpty(struct Node *top) {
    return top == NULL;
}
int isFull(struct Node *top) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL) {
        return 1;
    } else {
        free(p); // Free the memory to avoid memory leak
        return 0;
    }
}

struct Node* push(struct Node *top, int x) {
    if (isFull(top)) {
        printf("Stack Overflow\n");
        return top; // Return top even if stack is full
    } else {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->data = x;
        p->next = top;
        top = p;
        return top;
    }
}

int pop(struct Node **top) { // struct Node **top: A pointer to a pointer to the top node.
    // This allows the function to modify the original top pointer.
    if (isEmpty(*top)) {
        printf("Stack Underflow\n");
        return -1; // Return a specific value to indicate underflow
    } else {
        struct Node* n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(struct Node *top, int pos) {
    struct Node* ptr = top;
    for (int i = 0; i < pos && ptr != NULL; i++) {
        ptr = ptr->next;
    }
    if (ptr != NULL) {
        return ptr->data;
    } else {
        return -1; // Return a specific value to indicate invalid position
    }
}
int main() {
    struct Node *top = NULL;
    top = push(top, 75);
    top = push(top, 76);
    top = push(top, 77);
    top = push(top, 78);
    printf("Stack elements after pushes:\n");
    linkedListTraversal(top);
    int element = pop(&top);
    printf("Popped element: %d\n", element);
    printf("Stack elements after pop:\n");
    linkedListTraversal(top);
    int peekedElement = peek(top, 2);
    printf("Element at position 2: %d\n", peekedElement);
    return 0;
}

