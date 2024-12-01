#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
    struct Node*prev;
};
struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void insertAtPosition(struct Node** head, int data, int position){
    struct Node* newNode=createNode(data);
    if(position==0){
        if(*head!=NULL){
            (*head)->prev=newNode;
        }
        newNode->next=*head;
        *head=newNode;
        return;
    }
    struct Node* current=*head;
    int currentPosition=0;
    while(current!=NULL && currentPosition < position -1){
        current=current->next;
        currentPosition++;
    }
    if(current!=NULL){
        newNode->next=current->next;
        newNode->prev=current;
        if(current->next!=NULL){
            current->next->prev=newNode;
        }
        current->next=newNode;
    }else{
        printf("postion out of Bounds\n");
        free(newNode);
    }
}

void printList(struct Node* head){
    struct Node*current=head;
    while(current !=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}
int main(){
    struct Node* head=NULL;
    insertAtPosition(&head,1,0);
    insertAtPosition(&head,2,1);
    insertAtPosition(&head,3,2);
    printf("Origianl List: ");
    printList(head);
    insertAtPosition(&head,4,1);
    printf("List after Inserting 4 at position 1: ");
    printList(head);
    return 0;
}