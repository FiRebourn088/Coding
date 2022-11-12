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

void delete(Node* *head){
    if(*head == NULL){
        cout << "LL empty" << endl;
        return;
    }
    
    if((*head) -> next == *head){
        cout << "LL now empty, last Node deleted: " << (*head) -> data << endl;
        head = NULL;
        return;
    }
    
    
}

int main()
{
    cout<<"Hello World";

    return 0;
}