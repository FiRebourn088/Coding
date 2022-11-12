#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void postOrder(Node *root){
    if(root != NULL){
        postOrder(root -> left);
        postOrder(root -> right);
        cout << root -> data << " ";
    }
}

void preOrder(Node *root){
    if(root != NULL){
        cout << root -> data << " ";
        preOrder(root -> left);
        preOrder(root -> right);
    }
}

void inOrder(Node *root){
    if(root != NULL){
        inOrder(root -> left);
        cout << root -> data << " ";
        inOrder(root -> right);
    }
}

int main()
{
    Node *root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    
    cout << "InOrder: ";
    inOrder(root);
    cout << endl;
    
    cout << "PreOrder: ";
    preOrder(root);
    cout << endl;
    
    cout << "PostOrder: ";
    postOrder(root);

    return 0;
}

