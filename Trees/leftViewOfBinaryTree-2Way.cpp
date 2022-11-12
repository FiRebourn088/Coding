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

void left_view(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node *> q;
    q.push(root);
    while(q.empty() == false){
        int n = q.size();
        for(int i = 0; i < n; i++){
            Node* temp = q.front();
            q.pop();
            
            if(i == 0){
                cout << temp -> data << " ";
            }
            
            if(temp -> left != NULL){
                q.push(temp -> left);
            }
            
            if(temp -> right != NULL){
                q.push(temp -> right);
            }
        }
    }
}

int main()
{
    Node *root=new Node(20);
	root->left=new Node(70);
	root->right=new Node(90);
	root->left->left=new Node(30);
	root->left->left=new Node(40);
	root->right->right=new Node(70);

    left_view(root);
    return 0;
}