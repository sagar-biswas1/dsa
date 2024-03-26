#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};


Node *btreeInput()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
    {
        root = NULL;
    }
    else
    {
        root = new Node(val);
    }
    queue<Node *> q;

    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        Node *ml;
        Node *mr;
        if (l == -1)
        {
            ml = NULL;
        }
        else
        {
            ml = new Node(l);
        }
        if (r == -1)
        {
            mr = NULL;
        }
        else
        {
            mr = new Node(r);
        }

        f->left = ml;
        f->right = mr;
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }

    return root;
}


int sum(Node *root){

    if(root==NULL){
        return 0;
    }
    if(!root->left && !root->right){
        return 0;
    }

    return sum(root->left)+sum(root->right)+root->val;
}
int main(){
 Node *root = btreeInput();

int s= sum(root);

cout<<s;
    return 0;
}