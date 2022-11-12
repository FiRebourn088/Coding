#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
    Node *next;
};

class linkedList{
    private:
        Node *head;
    public:
        linkedList(){
            head = NULL;
        }
        
        int calcSize();
        void insertStart(int data);
        void insertLast(int data);
        void insertPos(int pos, int data);
        void display();
};

int linkedList::calcSize(){
    Node *node = new Node();
    node = head;
    
    int size = 0;
    
    while(node != NULL){
        node = node -> next;
        size++;
    }
    return size;
}

void linkedList::insertStart(int data){
    Node *newNode = new Node();
    
    newNode -> data = data;
    newNode -> next = head;
    
    head = newNode;
}

void linkedList::insertLast(int data){
    Node *newNode = new Node();
    
    newNode -> data = data;
    newNode -> next = NULL;
    
    if(head == NULL){
        head = newNode;
        return;
    }
    
    Node *temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void linkedList::insertPos(int pos, int data){
    int size = calcSize();
    
    if(pos == 0){
        insertStart(data);
    }
    else if(pos < 1 || pos > size){
        cout << "Invalid Size." << endl;
    }else{
        Node *newNode = new Node();
        Node *temp = head;
        
        newNode -> data = data;
        newNode -> next = NULL;
        
        while(--pos){
            temp = temp -> next;
        }
        
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
}

void linkedList::display(){
    Node *node = new Node();
    node = head;
    
    while(node != NULL){
        cout << node -> data << " ";
        node = node -> next;
    }
    cout << endl;
}

int main()
{
    linkedList *list = new linkedList();
    
    list -> insertStart(10);
    list -> insertStart(20);
    list -> insertStart(30);
    
    list -> insertLast(40);
    list -> insertLast(50);
    
    list -> insertPos(2,60);
    
    list -> display();

    return 0;
}


















