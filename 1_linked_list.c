// ajj linked list padhenge
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
    head->data=7;
    head->next=second;

    //imp
    // pointer use karte waqt, kisi sub element ko access kare k liye "->" operator use karte hai
    // jab normal variable use karte hai tho, kisi sub eement ko access karne k liye "." operator use karte hai

    second->data=11;
    second->next=third;

    third->data=66;
    third->next=fourth;

    fourth->data=66;
    fourth->next=NULL;
    linkedListTraversal(head);
    return 0;
}