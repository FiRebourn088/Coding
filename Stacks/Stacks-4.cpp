#include <bits/stdc++.h>
using namespace std;

struct Stack{
    int* arr;
    int MAX;
    int top;
    Stack(int max){
        MAX = max;
        arr = new int [MAX];
        top = -1;
    }
    
    void Push(int x){
        if(top == MAX - 1){
            cout << "Stack overflow." << endl;
            return;
        }else{
            top++;
            arr[top] = x;
        }
    }
    
    int Pop(){
        if(top < 0){
            cout << "Stack underflow." << endl;
            return INT_MIN;
        }else{
            int x = arr[top];
            top--;
            return x;
        }
    }
    
    int Peek(){
        if(top < 0){
            cout << "Stack underflow." << endl;
            return INT_MIN;
        }else{
            return arr[top];
        }
    }
    
    int Size(){
        return (top + 1);
    }
    
    bool isEmpty(){
        return (top < 0); 
    }
    
    bool isFull(){
        return (top >= MAX - 1);
    }
    
    void Display(){
        int i;
        if(top < 0){
            cout << "Stack underflow." << endl;
        }
        for(i = top; i>= 0; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Stack S(10);
    S.Push(10);
    S.Push(20);
    S.Push(30);
    S.Push(40);
    S.Push(50);
    S.Push(60);
    S.Push(70);
    S.Push(80);
    S.Push(90);
    S.Push(100);
    cout << S.Pop() << endl;
    cout << S.Peek() << endl;
    cout << S.Size() << endl;
    S.Display();
    cout << S.isFull() << endl;
    cout << S.isEmpty() << endl;
    
    return 0;
}