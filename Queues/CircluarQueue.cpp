#include <bits/stdc++.h>
using namespace std;

class Queue{
    int front, rear;
    unsigned max;
    int* arr;
    
    public:
    Queue(int size){
        max = size;
        front = rear = -1;
        arr = new int [max];
    }
    void enqueue(int x);
    int dequeue();
    void display();
    bool isEmpty();
    bool isFull();
};

bool Queue::isFull(){
    if((front == rear + 1) || (front == 0 && rear == max - 1)){
        return true;
    }else
        return false;
}

bool Queue::isEmpty(){
    if(front == -1){
        return true;
    }else
        return false;
}

void Queue::display(){
    int i;
    if(isEmpty()){
        cout << "Queue empty." << endl;
    }else{
        cout << "Queue: ";
        for(i = front; i != rear; i = (i + 1) % max){
            cout << arr[i] << ",";
        }
        cout << arr[i];
    }
}

void Queue::enqueue(int x){
    if(isFull()){
        cout << "Queue Full." << endl;
    }else{
        if(front == -1){
            front = 0;
        }
        rear = (rear + 1) % max;
        arr[rear] = x;
        cout << x << " enqueued." << endl;
    }
}

int Queue::dequeue(){
    int item;
    if(isEmpty()){
        cout << "Queue Empty." << endl;
        return INT_MIN;
    }else{
        item = arr[front];
        if(front == rear){
            front = rear = -1;
        }else{
            front = (front + 1) % max;
        }
        cout << item << " dequeued." << endl;
        return item;
    }
}

int main()
{
    Queue queue = Queue(6);
    
    queue.dequeue();
    
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    
    queue.dequeue();
    queue.dequeue();
    
    queue.enqueue(50);
    queue.enqueue(60);
    queue.enqueue(70);
    queue.enqueue(80);
    queue.enqueue(90);

    queue.display();
    
    return 0;
}
