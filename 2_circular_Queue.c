#include <stdio.h>
#include <stdlib.h>
// ye yaad rakho
// i=i+1 -> linear increment
// i=(i+1)%size ->
struct circularqueues {
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct circularqueues *q) {
    if ((q->r + 1) % q->size == q->f) {
        return 1;
    }
    return 0;
}

int isEmpty(struct circularqueues *q) {
    if (q->r == q->f) {
        return 1;
    }
    return 0;
}

void enqueue(struct circularqueues *q, int val) {
    if (isFull(q)) {
        printf("The Queue is full\n");
    } else {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
    }
}

int dequeue(struct circularqueues *q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("The Queue is empty\n");
    } else {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main() {
    struct circularqueues q;
    q.size = 100; // Total buffer size (one more than the max elements)
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    
    // Enqueue a few elements
    enqueue(&q, 12);
    enqueue(&q, 13);
    
    // Dequeue elements
    printf("Dequeuing the element %d\n", dequeue(&q));
    printf("Dequeuing the element %d\n", dequeue(&q));

    // Free allocated memory
    free(q.arr);
    return 0;
}
