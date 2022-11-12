#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

int calcSize(Node *root){
    if(root == NULL){
        return 0;
    }
    else
        return 1 + calcSize(root -> left) + calcSize(root -> right);
}

int main()
{
    Node *root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);
    root -> left -> left -> left = new Node(8);
    root -> left -> left -> right = new Node(9);
     cout << calcSize(root);

    return 0;
}