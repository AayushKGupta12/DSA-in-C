#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* addToEmpty(int data) {
    struct node* temp = malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = data;
    temp->next = temp;
    return temp;
}

struct node* addAtEnd(struct node* tail, int data) {
    struct node* newP = malloc(sizeof(struct node));
    if (newP == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newP->data = data;
    newP->next = tail->next;
    tail->next = newP;
    tail = newP;
    return tail;
}

struct node* createList(struct node* tail) {
    int i, n, data;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);

    if (n == 0) {
        return NULL;
    }

    printf("Enter element 1: ");
    scanf("%d", &data);
    tail = addToEmpty(data);

    for (i = 1; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        tail = addAtEnd(tail, data);
    }
    return tail;
}

void print(struct node* tail) {
    if (tail == NULL) {
        printf("No nodes in the list\n");
        return;
    }
    struct node* p = tail->next;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != tail->next);
    printf("\n");
}
// to delete the first node
struct node* delFirst(struct node* tail) {
    if (tail == NULL) {
        return NULL;
    }
    if (tail->next == tail) {
        free(tail);
        return NULL;
    }
    struct node* temp = tail->next;
    tail->next = temp->next;
    free(temp);
    return tail;
}

int main() {
    struct node* tail = NULL;
    tail = createList(tail);
    printf("\nList before deletion: ");
    print(tail);
    tail = delFirst(tail);
    printf("List after deletion: ");
    print(tail);
    return 0;
}
