

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

int calculate_node(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return calculate_node(root->left) + calculate_node(root->right) + 1;
}
int main()
{
    Node *root = btreeInput();

    int depth = max_height(root);
    int expected = pow(2, depth) - 1;
    int actual = calculate_node(root);
    if (expected == actual)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
