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

void spiral(Node* root){
    if(root == NULL)
        return;
    queue<Node *> q;
    stack<int> s;
    bool l_r = true;
    q.push(root);
    while(q.empty() == false){
        int n = q.size();
        for(int i = 0; i < n; i++){
            Node* temp = q.front();
            q.pop();
            if(l_r)
                cout << temp -> data << " ";
            else
                s.push(temp -> data);
            if(temp -> left != NULL)
                q.push(temp -> left);
            if(temp -> right != NULL)
                q.push(temp -> right);
        }
        if(l_r == false){
            while(s.empty() == false){
                cout << s.top() << " ";
                s.pop();
            }
        }
        l_r = !l_r;
    }
}

int main()
{
    Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);

    spiral(root);
    return 0;
}