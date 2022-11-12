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

void printKDistance(Node *root, int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout << root -> data << " ";
    }
    else{
        printKDistance(root -> left, k - 1);
        printKDistance(root -> right, k - 1);
    }
}

int main()
{
    Node *root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    printKDistance(root,2);
    return 0;
}
