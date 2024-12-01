#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *prev;
    struct Node*next;
};

void InsertAtend(struct Node* head,int data){
    struct Node* ptr=head;
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }

    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    
    ptr->next=newNode;
    newNode->prev=ptr;
}

void display(struct Node*node){
    struct Node*end;
    printf("list in forward Direction: \n");
    while(node!=NULL){
        printf("%d ",node->data);
        end=node;
        node=node->next;
    }
    printf("\n List in backward Direction : \n");
    while(end!=NULL){
        printf("%d ",end->data);
        node=end;
        end=end->prev;
    }
}

/*************************/
void insertStart(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}
int main(){
    struct Node*head=NULL;
    insertStart(&head, 12);
    insertStart(&head, 16);
    insertStart(&head, 20);
    InsertAtend(head, 10);
    display(head);
    return 0;
    InsertAtend(head,10);
    display(head);
    return 0;
}