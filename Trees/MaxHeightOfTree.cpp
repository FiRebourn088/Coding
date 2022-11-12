#include <bits/stdc++.h>
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

int maxHeight(Node *node){
    if(node == NULL){
        return 0;
    }
    else{
        int lHeight = maxHeight(node -> left);
        int rHeight = maxHeight(node -> right);
        
        if(lHeight > rHeight)
            return (lHeight + 1);
        else
            return (rHeight + 1);
    }
}

int main()
{
    Node *root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    
    cout << maxHeight(root);

    return 0;
}