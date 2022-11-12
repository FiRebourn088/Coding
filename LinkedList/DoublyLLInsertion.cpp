#include <iostream>
using namespace std;

class Node{
    public:
        int data;
    Node *next;
    Node *prev;
};

void insertStart(Node* *head, int data){
    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> next = *head;
    newNode -> prev = NULL;
    
    if(*head != NULL){
        (*head) -> prev = newNode;
    }
    *head = newNode;
}

void insertLast(Node* *head, int data){
    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;
    
    if(*head == NULL){
        *head = newNode;
        newNode -> prev = NULL;
        return;
    }
    Node *temp = new Node();
    temp = *head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> prev = temp;
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
    insertStart(&head,30);
    insertStart(&head,40);
    insertStart(&head,50);
    insertStart(&head,60);
    insertStart(&head,70);
    insertStart(&head,80);
    insertStart(&head,90);
    
    display(head);
    
    insertLast(&head,100);
    insertLast(&head,40);
    insertLast(&head,30);
    insertLast(&head,20);
    insertLast(&head,10);
    
    display(head);

    return 0;
}