
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
    if (val == -1)
        return NULL;

    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1)
        {
            f->left = new Node(l);
            q.push(f->left);
        }
        if (r != -1)
        {
            f->right = new Node(r);
            q.push(f->right);
        }
    }

    return root;
}

void leftTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if(root->left){
         leftTraversal(root->left);
         cout << root->val << " ";
    }else{leftTraversal(root->right);
         cout << root->val << " ";

    }
   
}

void rightTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if(root->right){
        cout << root->val << " ";
    rightTraversal(root->right);
    }else{
         cout << root->val << " ";
    rightTraversal(root->left);
    }
}
int main()
{
    Node *root = btreeInput();
    if (root != NULL)
    {
        leftTraversal(root->left);
        cout << root->val << " ";
        rightTraversal(root->right);
    }

    return 0;
}
