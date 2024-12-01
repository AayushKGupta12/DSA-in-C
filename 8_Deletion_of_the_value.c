// ajj linked list mai deletion padhenge
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
void linkedListTraversal(struct Node*ptr){
    while(ptr!=NULL){
    printf("Element : %d\n",ptr->data);
    ptr=ptr->next;
    }
}
//to delete the Value of the linkedlist
struct Node* deleteValue(struct Node*head,int data){
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->data!=data && q->next!=NULL){
        p=p->next;
        q=q->next;
    } 
    
    p->next=q->next;
    free(q);
    
    return head;
}
int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    // Allocate Memory for nodes in the linked ist in Heap
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    //IMPORTANT
    //Pointer use karte waqt, kisi sub element ko access kare k liye "->" operator use karte hai
    //Jab normal variable use karte hai tho, kisi sub eement ko access karne k liye "." operator use karte hai
    head->data=7;
    head->next=second;

    second->data=3;
    second->next=third;

    third->data=8;
    third->next=fourth;

    fourth->data=1;
    fourth->next=NULL;
    printf("Linked List Before Deletion");
    linkedListTraversal(head);
    head=deleteValue(head,8); 
    printf("Linked List after Deletion");
    linkedListTraversal(head);
    return 0;
} 