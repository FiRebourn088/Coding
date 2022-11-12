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
    
    newNode -> next = (*head) -> next;
    (*head) -> next = newNode;
    
    int temp = (*head) -> data;
    (*head) -> data = newNode -> data;
    newNode -> data = temp;
    
    *head = newNode;
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
    display(head);
    
    insertLast(&head, 10);
    insertLast(&head, 20);
    insertLast(&head, 30);
    insertLast(&head, 40);
    insertLast(&head, 50);
    insertLast(&head, 60);
    insertLast(&head, 70);
    insertLast(&head, 80);
    insertLast(&head, 90);
    insertLast(&head, 100);
    insertLast(&head, 110);

    display(head);
    
    return 0;
}