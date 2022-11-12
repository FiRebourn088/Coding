#include <bits/stdc++.h>
using namespace std;

struct Stack{
    vector<int> vec;
    
    void Push(int x){
        vec.push_back(x);
    }
    
    int Pop(){
        if(isEmpty()){
            return INT_MIN;
        }
        int x = vec.back();
        vec.pop_back();
        return x;
    }
    
    int Peek(){
        if(isEmpty()){
            cout << "Stack Empty." << endl;
            return INT_MIN;
        }
        return vec.back();
    }
    
    bool isEmpty(){
        return vec.empty();
    }
    
    int Size(){
        return vec.size();
    }
    
    void Display(){
        vector<int>::iterator i;
        for(i = vec.end() - 1; i >= vec.begin(); i--){
            cout << *i << " ";
        }
        cout << endl;
    }
};

int main(){
    Stack S;
    S.Push(10);
    S.Push(20);
    S.Push(30);
    S.Push(40);
    S.Push(50);
    S.Push(60);
    S.Push(70);
    cout << S.Pop() << " element popped." << endl;
    cout << S.Peek() << endl;
    cout << S.Size() << endl;
    cout << S.isEmpty() << endl;
    S.Display();
    
    return 0;
}