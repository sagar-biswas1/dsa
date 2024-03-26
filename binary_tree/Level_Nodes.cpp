
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
void print_level(Node *root, int level) {
    int depth = max_height(root)-1;
    
    if (level >= 0 && level <= depth) {
        queue<pair<Node *, int>> q;
        if (root != NULL)
            q.push({root, 0});
        while (!q.empty()) {
            
            pair<Node *, int> f = q.front();
            q.pop();
            Node *n = f.first;
            int l = f.second;
            if (l>level) break;
            if (l == level) {
                cout << n->val << " ";
            }
            if (n->left)
                q.push({n->left, l + 1});
            if (n->right)
                q.push({n->right, l + 1});
        }
    } else {
        cout << "Invalid" << endl;
    }
}
int main()
{
    Node *root = btreeInput();
    int l;
    cin>>l;
    print_level(root,l);
    
    return 0;
}
