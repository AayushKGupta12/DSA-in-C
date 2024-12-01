#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct nodeD{
    struct node* prev;
    int data;
    struct node* next;
};
// Only one node, which is pointing to is
struct node* circularSingly(int data){
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;
}

struct noce* circularDoubly( int data){
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    temp->prev=temp;
    return temp;v
}

int main(){
    int data=34;
    struct node* tail;
    tail=circularSingly(data);
    
    printf("%d \n",tail->data);
    return 0;
}