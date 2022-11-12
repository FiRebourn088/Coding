#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue{
    int front, rear, currSize;
    unsigned size;
    int* a;
};

struct Queue* createQueue(unsigned size){
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue -> size = size;
    queue -> front = queue -> currSize = 0;
    queue -> rear = size - 1;
    queue -> a = (int*) malloc(queue -> size * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue){
    if(queue -> currSize == queue -> size){
        printf("\nQueue Overflow.");
    }
    return (queue -> currSize == queue -> size);
}

int isEmpty(struct Queue* queue){
    if(queue -> currSize == 0){
        printf("\nQueue Underflow.");
    }
    return (queue -> currSize == 0);
}

void enqueue(struct Queue* queue, int item){
    if(isFull(queue)){
        return;
    }
    
    queue -> rear = (queue -> rear + 1) % queue -> size;
    queue -> a[queue -> rear] = item;
    queue -> currSize = queue -> currSize + 1;
    printf("\n%d enqueued at pos: %d.",item,queue -> rear);
}

void dequeue(struct Queue* queue){
    if(isEmpty(queue)){
        return;
    }
    
    int item = queue -> a[queue -> front];
    queue -> front = (queue -> front + 1) % queue -> size;
    queue -> currSize = queue -> currSize - 1;
    printf("\n%d dequeued, new front at pos: %d",item,queue -> front);
}

void display(struct Queue* queue){
    if(queue -> currSize == 0){
        printf("\nQueue empty.");
    }
    else{
        int i = queue -> front, j;
        printf("\nQueue: ");
        
        for(j = 0; j < queue -> currSize; j++){
            printf("%d ", queue -> a[(i + j) % queue -> size]);
        }
    }
}

int main()
{
    struct Queue* queue = createQueue(5);
    
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    
    dequeue(queue);
    dequeue(queue);
    
    display(queue);

    return 0;
}