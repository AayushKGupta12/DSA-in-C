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
//to delete an Index element of the linkedlist
struct Node* deleteAtIndex(struct Node*head, int index){
    struct Node *p=head;
    struct Node *q=head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    } 
    p->next = q->next;
    free(q);
    return head;
}
/*1. struct Node* deleteAtIndex(struct Node* head, int index)
   - This function takes two parameters:
     - `head`: A pointer to the head of the linked list.
     - `index`: The index at which the node needs to be deleted.

2. Variable Declarations:
   struct Node *p = head;
   struct Node *q = head->next;
   - `p`: A pointer that will traverse the list up to the node just before the node to be deleted.
   - `q`: A pointer that will traverse the list up to the node to be deleted.

3. Traversing to the Desired Index:
   for (int i = 0; i < index - 1; i++) {
       p = p->next;
       q = q->next;
   }
   - The loop runs from 0 to `index - 1`. This is because we want `p` to stop at the node just before the node to be deleted, so it should stop at `index - 1`.
   - At each iteration, both `p` and `q` move one step forward in the linked list.

4. Deleting the Node:
p->next = q->next;
   free(q);
   - After the loop, `p` points to the node just before the node to be deleted, and `q` points to the node to be deleted.
   - To delete the node, `p->next` is adjusted to skip `q`, effectively removing `q` from the list.
   - The memory occupied by `q` is freed using `free()` to prevent memory leaks.

5. Returning the Updated Head:
   return head;
This function essentially finds the node just before the node to be deleted and adjusts its `next` pointer to skip the node to be deleted. Then, it frees the memory occupied by the node to be deleted and returns the updated head of the list.
*/
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
    head=deleteAtIndex(head,2); 
    //to delete the 2nd element of the LL AFTER DELETING THE FIRST ELEMENT
    //head=deleteFirst(head); 
    printf("Linked List after Deletion");
    linkedListTraversal(head);
    return 0;
} 