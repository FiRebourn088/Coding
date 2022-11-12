#include <iostream>
using namespace std;

class Node{
    public:
        int data;
    Node *next;
    Node *prev;
};

void insert(Node* *head, int data){
    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> next = *head;
    newNode -> prev = NULL;
    if(*head != NULL){
        (*head) -> prev = newNode;
    }
    *head = newNode;
}

void deleteVal(Node* *head, int del){
    Node *temp = new Node();
    temp = *head;
    Node *previous = new Node();
    
    if(temp -> next == NULL){
        *head = NULL;
        free(temp);
        cout << "Value deleted: " << del << endl;
        return;
    }
    
    if(temp != NULL && temp -> data == del){
        *head = temp -> next;
        (*head) -> prev = NULL;
        cout << "Value deleted: " << del << endl;
        free(temp);
        return;
    }
    
    while(temp != NULL && temp -> data != del){
        previous = temp;
        temp = temp -> next;
    }
    
    if(temp == NULL){
        cout << "Item not found" << endl;
        return;
    }
    
    previous -> next = temp -> next;
    if(temp -> next == NULL){
        cout << "Value deleted: " << del << endl;
        free(temp);
        return;
    }
    Node *temp2 = new Node();
    
    temp2 = temp -> next;
    temp2 -> prev = previous;
    
    free(temp);
    cout << "Value deleted: " << del << endl;
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
    
    insert(&head,10);
    insert(&head,20);
    insert(&head,30);
    insert(&head,40);
    insert(&head,50);
    insert(&head,60);
    insert(&head,70);
    insert(&head,80);
    
    display(head);
    
    deleteVal(&head,30);
    deleteVal(&head,60);
    
    display(head);
    
    return 0;
}

