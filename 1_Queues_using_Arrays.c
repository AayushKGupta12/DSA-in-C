#include<stdio.h>
#include<stdlib.h>
struct queues{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queues *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct queues *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct queues*q,int val){
    if(isFull(q)){
        printf("The Queue is full\n");
    }else{
        q->r++;
        q->arr[q->r]=val;
    }
}

int dequeue (struct queues *q){
    int a=-1;       // what is the use of giving -1 to it            
    if(isEmpty(q)){
        printf("This Queues id Empty\n");
    }else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}
int main(){
    struct queues q;
    q.size=100;
    q.f=q.r=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));
    // enqueue few elements
    enqueue(&q,12); 
    enqueue(&q,14);
    enqueue(&q,16);
    printf("Dequeing the element %d\n", dequeue(&q));
    printf("Dequeing the element %d\n", dequeue(&q));
    free(q.arr);
    return 0;
}