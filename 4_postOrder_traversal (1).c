#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
};

//iska Sequence hota hai left->right->root 
//postOrder Traversal
void postOrderTraversal(struct Node* node){
    if(node==NULL){
        return;
    }
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    printf(" %d ",node->data);
}

int main(){
    struct Node* root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->right->right=createNode(5);
    printf("Post Traversal : ");
    postOrderTraversal(root);
    return 0;
}