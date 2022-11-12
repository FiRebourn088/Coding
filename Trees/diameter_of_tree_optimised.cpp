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

int max_d = 0;

int height(Node* root){
    if(root == NULL)
        return 0;
    int lc = height(root -> left);
    int rc = height(root -> right);
    max_d = max(max_d, 1 + lc + rc);
    
    return 1 + max(lc, rc);
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

    cout << height(root) << endl;
    cout << max_d;
    
    return 0;
}