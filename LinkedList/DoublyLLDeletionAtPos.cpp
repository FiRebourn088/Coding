#include <iostream>
using namespace std;

class Node{
    public:
        int data;
    Node *next;
    Node *prev;
};

int calcSize(Node *node){
    int size = 0;
    while(node != NULL){
        node = node -> next;
        size++;
    }
    return size;
}

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

void deleteVal(Node* *head, int pos){
    Node *temp = new Node();
    temp = *head;
    Node *previous = new Node();
    
    int size = calcSize(*head);
    if(pos < 1 || pos > size){
        cout << "Invalid size" << endl;
        return;
    }
    if(pos == 1){
        *head = temp -> next;
        (*head) -> prev = NULL;
        cout << "Value deleted: " << temp -> data << endl;
        free(temp);
        return;
    }
    
    while(--pos){
        previous = temp;
        temp = temp -> next;
    }
    previous -> next = temp -> next;
    Node *temp2 = new Node();
    temp2 = temp -> next;
    temp2 -> prev = previous;
    cout << "Value deleted: " << temp -> data << endl;
    free(temp);
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
    insert(&head,90);
    insert(&head,100);

    display(head);
    
    deleteVal(&head, 1);
    deleteVal(&head, 5);
    deleteVal(&head, 7);
    
    display(head);
    
    return 0;
} 


