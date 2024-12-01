// Linked list using Queue
#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node*next;
};

void linkedListTraversal(struct Node*ptr){
   printf("Printing the elements of this LinkiedList\n");
   while(ptr!=NULL){
      printf("The Element : %d\n",ptr->data);
      ptr=ptr->next;
   }
}

struct Node *f=NULL;
struct Node *r=NULL;

void enqueue(int val){
   struct Node *n=(struct Node*)malloc(sizeof(struct Node));
   if(n==NULL){
      printf("Queue is Full");
   }else{
      n->data=val;
      n->next=NULL;
      if(f==NULL){
         f=r=n;
      }
      else{
         r->next=n;
         r=n;
      }

   }
}

int dequeue(){
   if(f==NULL){
      printf("Queue is Empty");
         return-1;
   }else{
     struct Node*temp=f; // temprotraly stroed front node
     int val=temp->data; // stroe the data to return it
     f=f->next;          // MOve the front pointer tp the next node
     free(temp);         // Free The memoery of the removes node
     if(f==NULL){        // free the memeory of the removes node
      r==NULL;
     }
     return val;         // return the dequed value
}
}

int main(){
  linkedListTraversal(f);
  enqueue(34);
  enqueue(4);
  enqueue(7);
  enqueue(69);
  enqueue(45);
  linkedListTraversal(f);
  dequeue(f);
  linkedListTraversal(f);
  return 0;
}