#include <iostream>
using namespace std;

class Node{
    public:
        int data;
    Node *next;
};

void insertStart(Node* *head, int data){
    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;
    
    if(*head == NULL){
        *head = newNode;
        newNode -> next = *head;
        return;
    }
    
    newNode -> next = (*head) -> next;
    (*head) -> next = newNode;
    
    int temp = (*head) -> data;
    (*head) -> data = newNode -> data;
    newNode -> data = temp;
}

void display(Node *head){
    if(head == NULL){
        return;
    }
    Node *temp = head;
    do{
        cout << temp -> data << " ";
        temp = temp -> next;
    }while(temp != head);
}

int main()
{
    Node *head = NULL;
    
    insertStart(&head,10);
    insertStart(&head,20);
    insertStart(&head,30);
    insertStart(&head,40);
    insertStart(&head,50);
    
    display(head);

    return 0;
}