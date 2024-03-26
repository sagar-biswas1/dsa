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

void preorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}

void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

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

int count_nodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return count_nodes(root->left) + count_nodes(root->right) + 1;
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

int count_leaf(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return count_leaf(root->left) + count_leaf(root->right);
}

int max_height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int l = max_height(root->left);
    int r = max_height(root->right);

    return max(l, r) + 1;
}
int main()
{
    // Node *root = new Node(10);
    // Node *a = new Node(20);
    // Node *b = new Node(30);
    // Node *c = new Node(40);
    // Node *d = new Node(50);
    // Node *e = new Node(60);
    // Node *f = new Node(70);
    // Node *g = new Node(80);
    // Node *h = new Node(90);
    // Node *i = new Node(100);

    // root->left = a;
    // root->right = b;
    // a->left = c;
    // a->right = h;
    // c->right = e;
    // b->right = d;
    // d->left = f;
    // d->right = g;
    // h->right = i;

    // preorderTraversal(root);
    // //root->left->right
    // cout<< endl;
    // postorderTraversal(root);
    // //left->right->root
    // cout<< endl;
    // inorderTraversal(root);
    cout << " hello" << endl;
    Node *root = btreeInput();

    levelOrder(root);
    cout << endl;
    cout << max_height(root) << endl;
    return 0;
}


