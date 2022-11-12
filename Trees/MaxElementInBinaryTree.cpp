#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

int maxSize(Node *root){
    if(root == NULL){
        return INT_MIN;
    }
    else
        return max(root -> data, max(maxSize(root -> left),maxSize(root -> right)));
}

int main()
{
    Node *root = new Node(70);
    root -> left = new Node(50);
    root -> right = new Node(90);
    root -> left -> left = new Node(40);
    root -> left -> right = new Node(60);
    root -> right -> left = new Node(80);
    root -> right -> right = new Node(100);
    
    cout << maxSize(root);
    return 0;
}
