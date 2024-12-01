#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};


void insertAtBeg(struct Node**head,int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=*head;
    newNode->prev=NULL;
    if(*head!=NULL)
        (*head)->prev=newNode;
    *head=newNode;
}


void display(struct Node*node){
    struct Node*end;
    printf("List in Forward Direction: \n");
    while(node!=NULL){
        printf("%d \n",node->data);
        end=node;
        node=node->next;
    }
    printf("List in backward direction");
    while(end!=NULL){
        printf("%d \n",end->data);
        end=end->prev;
    }
}

int main(){
    struct Node*head=NULL;
    insertAtBeg(&head,12);
    insertAtBeg(&head,16);
    insertAtBeg(&head,20);
    display(head);
    return 0;
}