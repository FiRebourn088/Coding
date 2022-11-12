#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
    Node *next;
};

int calcSize(Node *node){
    int size = 0;
    while(node != NULL){
        node = node->next;
        size++;
    }
    return size;
}

void insertStart(Node* *head, int data){
    Node *newNode = new Node();
    
    newNode -> data = data;
    newNode -> next = *head;
    
    *head = newNode;
}

void insertLast(Node* *head, int data){
    Node *newNode = new Node();
    
    newNode -> data = data;
    newNode -> next = NULL;
    
    if(*head == NULL){
        *head = newNode;
        return;
    }
    
    struct Node *temp = *head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void insertPos(int pos, int data, Node* *head){
    int size = calcSize(*head);
    
    if(pos < 1 || pos > size){
        cout << "Invalid size." << endl;
    }else{
        Node *temp = *head;
        Node *newNode = new Node();
        
        newNode -> data = data;
        newNode -> next = NULL;
        
        while(--pos){
            temp = temp -> next;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
}

void display(Node *node){
    while(node != NULL){
        cout << node -> data << " ";
        node = node -> next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    
    insertStart(&head,10);
    insertStart(&head,20);
    insertLast(&head,40);
    insertLast(&head,50);
    insertPos(3,60,&head);
    insertPos(2,70,&head);
    
    display(head);

    return 0;
}

