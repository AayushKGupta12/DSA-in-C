#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
    struct Node * prev;
};

struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data){
    struct Node* newNode=createNode(data);
    struct Node* last= *head;
    if( * head==NULL){
        *head=newNode;
        return;
    }
    while(last->next!=NULL){
        last = last->next;
    }
    last->next=newNode;
    newNode->prev=last;
}

void deleteNthNode(struct Node** head, int n){
    if(*head==NULL || n<=0){
        return;
    }
    struct Node* current =*head;
    for(int i=1; current !=NULL && i<n ; i++){
        current = current -> next;
    }
    
    if(current == NULL){
        return;
    }
    if(current->next!=NULL){
        current->next->prev=current->prev;
    }
    if(current-> prev !=NULL){
        current->prev->next= current-> next;
    }
    free(current);
}

void printList(struct Node* node){
    while(node!=NULL){
        printf("%d ",node->data);
        node=node->next;
    }
    printf("\n");
}
int main(){
    struct Node* head=NULL;
    insertAtEnd(&head,10);
    insertAtEnd(&head,20);
    insertAtEnd(&head,30);
    insertAtEnd(&head,40);
    printf("original List : ");
    printList(head);
    int n=3;
    deleteNthNode(&head,n);
    printf("List after deleting %d th node: ", n);
    printList(head);
    return 0;
}