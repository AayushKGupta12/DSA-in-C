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
// insertion at between any node. Show segmentztion fault when inserted at the beginniing or atr end
struct Node*insertAtIndex(struct Node *head, int data, int index){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node*p=head;
    int i=0;
    while (i !=index-1){
        p=p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
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
    
    linkedlistTraversal(head);
    insertAtIndex(head,14,2);
    linkedlistTraversal(head);

    return 0;
}