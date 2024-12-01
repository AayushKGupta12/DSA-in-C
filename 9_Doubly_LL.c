#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
    struct node*prev;
};

struct node*head=NULL;
void create(){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:\n");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }else{
        struct node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
}

int main(){
    int choice=1;
    while(choice){
        create();
        printf("Do you want to countinue\n");
        printf("If yes, press 1 or else 0 : ");
        scanf("%d",&choice);
    }
    struct node*temp=head;
    printf("doubly Linked List : \n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}