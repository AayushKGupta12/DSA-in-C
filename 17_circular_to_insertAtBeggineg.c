#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};
struct node* addToEmpty(int data){
    struct node* first=malloc(sizeof(struct node));
    first->data=data;
    first->next=first;
    return first;
}

struct node*addAtBeg(struct node*tail, int data){
    struct node* newP=malloc(sizeof(struct node));
    newP->data=data;
    newP->next=tail->next;
    tail->next=newP;
    return tail;
}

void print(struct node* tail){
    struct node* p=tail->next;
    do{
        printf("%d -> ",p->data);
        p=p->next;
        }
        while(p!=tail->next);
        printf(" TO First ");
}


int main(){
    struct node* tail;
    tail = addToEmpty(5);
    tail = addAtBeg(tail,7);
    tail = addAtBeg(tail,9);
    tail = addAtBeg(tail,11);
    print(tail);
    return 0;
}