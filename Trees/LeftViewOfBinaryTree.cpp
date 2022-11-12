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

/*void print_view(Node* root){
    if(root == NULL){
        return;
    }
    else
        cout << root -> data << " ";
        print_view(root -> left);
}*/

int Max = 0;

void print_left(Node* root, int curr_level){
    if(root == NULL)
        return;
    if(Max < curr_level){
        cout << root -> data << " ";
        Max = curr_level;
    }
    print_left(root -> left, curr_level + 1);
    print_left(root -> right, curr_level + 1);
}

void helper(Node* root){
    print_left(root, 1);
}

int main()
{
    Node *root=new Node(20);
	root->left=new Node(70);
	root->right=new Node(90);
	root->left->left=new Node(30);
	root->left->left=new Node(40);
	root->right->right=new Node(70);
	
	helper(root);

    return 0;
}