#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
    struct Node*prev;
};

void printList(struct Node*head){
    struct Node* last;
    printf("Forward Direction");
    while(head!=NULL){
        printf("%d ",head->data);
        last = head;
        head = head->next;
    }
    printf("NULL\n");
}

void append(struct Node**head,int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node* last= *head;
    newNode->data=data;
    newNode->next=NULL;
    if(*head==NULL){
        newNode->prev=NULL;
        *head=newNode;
        return;
    }
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=newNode;
    newNode->prev=last;
}

void deleteNode(struct Node**head, struct Node*del){
    if(*head==NULL||del==NULL){
        return;
    }
    if(*head==del){
        *head=del->next;
    }
    if(del->next!=NULL){
        del->next->prev=del->prev;
    }
    if(del->prev!=NULL){
        del->prev->next=del->next;
    }
    free(del);
}
int main(){
    struct Node* head=NULL;
    append(&head,1);
    append(&head,2);
    append(&head,3);
    append(&head,4);
    printf("Original list:\n");
    printList(head);
    deleteNode(&head,head->next);
    printf("list after deletiong the second node:\n");
    printList(head);
    return 0;
}