#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};

struct Node* f=NULL;
struct Node* r=NULL;

void enqueue(int val){
    struct Node*n=(struct Node*)malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is Full");
    }else{
        n->data=val;
        n->next=NULL;
        if(f==NULL){
            f=r=n;
            r->next=f;
        }else{
            r->next=n;
            r=n;
            r->next=f;
        }
    }
}

int dequeue(){
    if(f==NULL){
        printf("Queue is Empty");
        return -1;
    }else{
        struct Node*temp=f;
        int val=temp->data;

        if(f==r){
            f=r=NULL;
        }else{
            f=f->next;
            r->next=f;
        }
        free(temp);
        return val;
    }
}

void linkedListTraversal(){
    if(f==NULL){
        printf("Queue is EMpty");
        return ;
    }
    struct Node* ptr=f;
    printf("Printing the element of this Circular Queue");
    do{
        printf("The element : %d\n",ptr->data);
        ptr=ptr->next;

    }while(ptr!=f);
}

int main(){
    linkedListTraversal();  
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(69);
    enqueue(45);
    linkedListTraversal();  
    
    printf("\nDequeued: %d\n", dequeue());  // Dequeue the front element
    linkedListTraversal();                 // Print the queue after dequeue
    
    printf("\nDequeued: %d\n", dequeue());  // Dequeue another element
    linkedListTraversal();                 // Print the queue after dequeue
    
    return 0;
}
