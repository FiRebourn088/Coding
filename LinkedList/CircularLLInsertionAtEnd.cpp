#include <iostream>
using namespace std;

class Node{
    public:
        int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertLast(Node* *head, int data){
    Node *newNode = new Node(data);
    
    if(*head == NULL){
        *head = newNode;
        newNode -> next = *head;
        return;
    }
    
    Node *temp = *head;
    
    while(temp -> next != *head){
        temp = temp -> next;
    }
    
    temp -> next = newNode;
    newNode -> next = *head;
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
    cout << endl;
}

int main()
{
    Node *head = NULL;
    
    insertLast(&head,10);
    insertLast(&head,20);
    insertLast(&head,30);
    insertLast(&head,40);
    insertLast(&head,50);
    
    display(head);

    return 0;
}