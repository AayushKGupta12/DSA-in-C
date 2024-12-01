#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void linkedlistTraversal(struct Node*ptr){
    while(ptr!=NULL){
        printf("Element : %d \n",ptr->data);
        ptr = ptr->next;
    }
}

// insertion at end.
struct Node* insertAtEnd(struct Node* head, int data){ 
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    
    struct Node*p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next=NULL;
    return head;
}

int main(){
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    struct Node* second=(struct Node*)malloc(sizeof(struct Node));
    struct Node* third=(struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth=(struct Node*)malloc(sizeof(struct Node));
    
    head->data=2;
    head->next=second;

    second->data=4;
    second->next=third;

    third->data=6;
    third->next=fourth;

    fourth->data=8;
    fourth->next=NULL;
    printf("Linked List Before Insertion \n");
    linkedlistTraversal(head);
    head=insertAtEnd(head,20);
    printf("Linked List After Insertion \n");
    linkedlistTraversal(head);

    return 0;
}