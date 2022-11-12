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

Node *getLCA(Node* root, int val1, int val2){
    if(root == NULL)
        return NULL;
    if(root -> data == val1 || root -> data == val2)
        return root;
    Node *leftLCA = getLCA(root -> left, val1, val2);
    Node *rightLCA = getLCA(root -> right, val1, val2);
    
    if(leftLCA && rightLCA)
        return root;
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main()
{
    Node *root = new Node(70);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> left -> left = new Node(50);
    root -> left -> left -> left = new Node(60);
    root -> left -> left -> left -> left = new Node(90);
    root -> left -> left -> right = new Node(40);
    root -> left -> left -> right -> right = new Node(110);
    root -> left -> right = new Node(10);
    root -> left -> right -> right = new Node(80);
    root -> left -> right -> right -> right = new Node(100);

    cout << getLCA(root,50,110);
    
    return 0;
}
