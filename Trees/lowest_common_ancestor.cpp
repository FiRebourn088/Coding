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

bool findPath(Node* root, vector<Node *> &p, int n){
    if(root == NULL)
        return false;
    p.push_back(root);
    
    if(root -> data == n)
        return true;
    
    if(findPath(root -> left, p, n) || findPath(root -> right, p, n))
        return true;
    p.pop_back();
    return false;
}

Node *lca(Node* root, int val1, int val2){
    vector<Node *> p1,p2;
    if(findPath(root, p1, val1) == false || findPath(root, p2, val2) == false)
        return NULL;
    
    for(int i = 0; i < p1.size() && i < p2.size(); i++){
        if(p1[i] != p2[i])
            return p1[i - 1];
    }
    return NULL;
}

int main()
{
    Node *root=new Node(70);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(50);
	root->left->right=new Node(10);
	root->left->left->left=new Node(60);
	root->left->left->right=new Node(40);
	root->left->left->left->left=new Node(90);
	root->left->left->right->right=new Node(110);
	root->left->right->right=new Node(80);
	root->left->right->right->right=new Node(100);
	
	Node *result = lca(root,90,110);
	cout << result -> data;

    return 0;
}
