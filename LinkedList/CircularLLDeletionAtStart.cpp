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

void deleteStart(Node* *head){
    
    if(*head == NULL){
        cout << "LL empty." << endl;
        return;
    }
    
    if((*head) -> next == *head){
        cout << "LL empty, last node deleted: " << (*head) -> data << endl;
        *head = NULL;
        return;
    }
    
    Node *curr = (*head) -> next;
    (*head) -> data = curr -> data;
    (*head) -> next = curr -> next;
    free(curr);
    
}

void insert(Node* *head, int data){
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
}

void display(Node *head){
    if(head == NULL){
        cout << "LL empty." << endl;
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
    
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);
    insert(&head, 60);
    insert(&head, 70);
    insert(&head, 80);
    insert(&head, 90);
    insert(&head, 100);
    
    display(head);
    
    deleteStart(&head);
    deleteStart(&head);
    deleteStart(&head);
    
    display(head);

    return 0;
}
