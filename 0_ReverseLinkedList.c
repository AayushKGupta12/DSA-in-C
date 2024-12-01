#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
struct Node {
    int data;               // Data part of the node
    struct Node* next;      // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for a new node
    newNode->data = data;   // Set the data
    newNode->next = NULL;   // Set the next pointer to NULL
    return newNode;         // Return the new node
}

// Function to reverse the linked list
struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;       // Pointer to keep track of the previous node
    struct Node* current = head;    // Pointer to keep track of the current node
    struct Node* next = NULL;       // Pointer to keep track of the next node

    // Traverse through the list
    while (current != NULL) {
        next = current->next;   // Store the next node
        current->next = prev;   // Reverse the link
        prev = current;         // Move prev to current
        current = next;         // Move current to next
    }
    return prev;                // New head of the reversed list
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data); // Print the data of the current node
        temp = temp->next;            // Move to the next node
    }
    printf("NULL\n");                 // End of the list
}

int main() {
    // Creating a simple linked list: 1 -> 2 -> 3 -> NULL
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    printf("Original List: ");
    printList(head);    // Print the original list

    head = reverse(head);   // Reverse the list

    printf("Reversed List: ");
    printList(head);    // Print the reversed list

    return 0;
}
