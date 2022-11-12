#include <bits/stdc++.h>
using namespace std;

class Queue{
    private:
        int front, rear, currSize;
        unsigned max;
        int* arr;
    
    public:
        
    Queue(int size){
        max = size;
        front = 0;
        rear = max - 1;
        currSize = 0;
        arr = new int [max];
    }
    
    void enqueue(int x);
    void dequeue();
    bool isFull();
    bool isEmpty();
    void display();
};

bool Queue::isFull(){
    if(currSize == max){
        cout << "Queue is full." << endl;
    }
    return (currSize == max);
}

bool Queue::isEmpty(){
    if(currSize == 0){
        cout << "Queue is empty." << endl;
    }
    return (currSize == 0);
}

void Queue::enqueue(int x){
    if(isFull()){
        return;
    }
    rear = (rear + 1) % max;
    arr[rear] = x;
    currSize++;
    cout << x << " enqueued." << endl;
}

void Queue::dequeue(){
    if(isEmpty()){
        return;
    }
    int item = arr[front];
    front = (front + 1) % max;
    currSize--;
    cout << item << " dequeued." << endl;
}

void Queue::display(){
    if(isEmpty()){
        cout << "Queue is Empty." << endl;
    }
    else{
        int i,j;
        cout << "Queue :" << endl;
        for(i = front, j = 0; j < currSize; j++){
            cout << arr[(i + j) % max] << " ";
        }
    }
}

int main()
{
    Queue queue = Queue(5);
    
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    
    queue.dequeue();
    queue.dequeue();
    
    queue.enqueue(50);
    
    queue.display();

    return 0;
}
