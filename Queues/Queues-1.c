#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void Enqueue(int x){
    if(rear == (SIZE - 1)){
        printf("Queue overflow\n");
    }
    else{
        if(front == -1){
            front = 0;
        }
        rear++;
        queue[rear] = x;
        printf("%d was enqueued.\n",x);
    }
}

void Dequeue(){
    if(front == -1){
        printf("Queue underflow.\n");
    }
    else{
        printf("Dequeued: %d\n", queue[front]);
        front++;
        
        if(front > rear){
            front = rear = -1;
        }
    }
}

void Display(){
    if(rear == -1){
        printf("Queue empty.\n");
    }
    else{
        int i;
        printf("Displaying Queue: ");
        
        for(i = front; i <= rear; i++){
            printf("%d ",queue[i]);
        }
    }
}

int main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    
    Display();

    return 0;
}