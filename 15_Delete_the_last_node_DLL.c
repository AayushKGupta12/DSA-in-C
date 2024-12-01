#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void addNode(Node**head, int data){
    Node*newNode=createNode(data);
    Node*last=*head;
    if(*head==NULL){
        *head=newNode;
        return;
    }
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=newNode;
    newNode->prev=last;
}

void deleteLastNode(Node** head){
    if(*head==NULL){
        printf("The list is empty\n");
        return;
    }
    Node*temp=*head;
    if(temp->next==NULL){
        free(temp);
        *head=NULL;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
}

void printList(Node* node){
    while(node !=NULL){
        printf("%d -> ",node-> data);
        node=node->next;
    }
    printf("NULL ");
}

int main(){
    Node* head=NULL;
    addNode(&head, 10);
    addNode(&head,20);
    addNode(&head,30);
    addNode(&head,40);
    printf("Original list : \n");
    printList(head);
    deleteLastNode(&head);
    printf("\nList adter deleting last Node: \n");
    printList(head);
    return 0;
}