#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for in-order Traversal (Left -> Node -> Right)
void inOrderTraversal(struct Node* node) {
    if (node == NULL) {
        return;
    }
    inOrderTraversal(node->left);
    printf(" %d ", node->data);
    inOrderTraversal(node->right);
}

// Function to insert a new node with the given key
void insert(struct Node* root, int key) {
    struct Node* prev = NULL;
    while (root != NULL) {
        prev = root;
        if (key == root->data) {
            printf("Cannot Insert %d as it is already in BST\n", key);
            return;
        } else if (key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    struct Node* newNode = createNode(key);
    if (key < prev->data) {
        prev->left = newNode;
    } else {
        prev->right = newNode;
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->right->right = createNode(5);

    printf("In Order Traversal:");
    inOrderTraversal(root);
    printf("\n");

    insert(root, 7);
    printf("Inserted 7\n");

    printf("In Order Traversal after insertion:");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
