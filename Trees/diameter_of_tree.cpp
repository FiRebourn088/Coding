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

int height(Node* root){
    if(root == NULL)
        return 0;
    else
        return 1+max(height(root -> left),height(root -> right));
}

int diameter(Node* root){
    if(root == NULL)
        return 0;
    int p_diam = 1 + height(root -> left) + height(root -> right);
    int lc = diameter(root -> left);
    int rc = diameter(root -> right);
    
    return max(p_diam,max(lc, rc));
}

int main()
{
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> left -> left -> left = new Node(6);
    root -> left -> right -> right = new Node(7);
    root -> left -> left -> left -> left = new Node(8);
    root -> left -> right -> right -> right = new Node(9);
    root -> right -> right = new Node(10);
    root -> right -> right -> right = new Node(11);
    
    cout << diameter(root);

    return 0;
}
