#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

void Insert(int key) {
    struct Node *t = root;
    struct Node *r, *p;

    if (root == NULL) {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = NULL;
        p->rchild = NULL;
        root = p;
        return;
    }

    while (t != NULL) {
        r = t;
        if (key < t->data) {
            t = t->lchild;
        } else if (key > t->data) {
            t = t->rchild;
        } else {
            return;
        }
    }

    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data) 
        r->lchild = p;
    else 
        r->rchild = p;
}

struct Node *Delete(struct Node *p, int key) {
    struct Node *q;

    if (p == NULL) {
        return NULL;
    }

    if (p->lchild == NULL && p->rchild == NULL) {
        if (p == root) {
            root = NULL;
        }
        free(p);
        return NULL;
    }

    if (key < p->data) {
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = Delete(p->rchild, key);
    } else {
        if (Height(p->lchild) > Height(p->rchild)) {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

// Preorder Traversal
void preorderTraversal(struct Node *node) {
    if (node == NULL) {
        return;
    }
    printf(" %d ", node->data);
    preorderTraversal(node->lchild); // Corrected 'left' to 'lchild'
    preorderTraversal(node->rchild);
}

// Search function
struct Node *Search(struct Node *root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (key == root->data) {
        return root;
    } else if (key < root->data) {
        return Search(root->lchild, key);
    } else {
        return Search(root->rchild, key);
    }
}

int main() {
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);

    preorderTraversal(root); // Changed to call the defined traversal function
    printf("\n");

    struct Node *temp;
    temp = Search(root, 40); // Fixed 'search' to 'Search'
    if (temp != NULL) {
        printf("Element %d is found\n", temp->data);
    } else {
        printf("Element is not found\n");
    }

    return 0;
}
