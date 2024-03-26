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

void levelOrder(Node *root)
{
    queue<Node *> q;

    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        cout << f->val << " ";
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}

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

void insert(Node *&root, int x)
{
    if (root ==NULL)
    {
        root = new Node(x);
    }
    if (x < root->val)
    {
        if (root->left == NULL)
        {
            root->left = new Node(x);
        }
        else
        {
            insert(root->left, x);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = new Node(x);
        }
        else
        {
            insert(root->right, x);
        }
    }
}
int main()
{
    Node *root = btreeInput();
    // int x;
    // cin >> x;
    insert(root, 13);
    insert(root, 32);
    levelOrder(root);
    return 0;
}
