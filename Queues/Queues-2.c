#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct myQueue{
    int front, rear;
    unsigned size;
    int* array;
};

struct myQueue* createQueue(unsigned size){
    struct myQueue* queue = (struct myQueue*) malloc(sizeof(struct myQueue));
    queue -> size = size;
    queue -> front = -1;
    queue -> rear = -1;
    
    queue -> array = (int*) malloc(queue -> size * sizeof(int));
    return queue;
}

int isFull(struct myQueue* queue){
    if(queue -> rear == queue -> size - 1){
        printf("\nQueue Overflow.");
    }
    return (queue -> rear == queue -> size - 1);
}

int isEmpty(struct myQueue* queue){
    if(queue -> front == -1){
        printf("\nQueue Underflow.");
    }
    return (queue -> front == -1);
}

void enqueue(struct myQueue* queue, int item){
    if(isFull(queue)){
        return;
    }
    if(queue -> front == -1){
        queue -> front = 0;
    }
    queue -> rear++;
    queue -> array[queue -> rear] = item;
    printf("\n%d enqueued.", item);
}

void dequeue(struct myQueue* queue){
    if(isEmpty(queue)){
        return;
    }
    
    int item = queue -> array[queue -> front];
    queue -> front++;
    
    if(queue -> front > queue -> rear){
        queue -> front = -1;
        queue -> rear = -1;
    }
    printf("\n%d dequeued.",item);
}

void display(struct myQueue* queue){
    if(queue -> rear == -1){
        printf("\nQueue empty.");
    }
    else{
        int i;
        printf("\nQueue: ");
        for(i = queue -> front; i <= queue -> rear; i++){
            printf("%d ",queue -> array[i]);
        }
    }
}

int main()
{
    struct myQueue* queue = createQueue(5);
    
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    
    dequeue(queue);
    dequeue(queue);
    
    display(queue);

    return 0;
}
