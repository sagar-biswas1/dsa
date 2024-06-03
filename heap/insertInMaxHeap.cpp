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
Node *convert(int arr[], int n, int l, int r)
{
    if (l > r)
        return NULL;
    int mid = (l + r) / 2;
    Node *root = new Node(arr[mid]);
    Node *leftRoot = convert(arr, n, l, mid - 1);
    Node *rightRoot = convert(arr, n, mid + 1, r);

    root->left = leftRoot;
    root->right = rightRoot;

    return root;
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

int main()
{

    vector<int> v;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {

        int x;
        cin >> x;
        v.push_back(x);

        int cur_index = v.size() - 1;

        while (cur_index != 0)
        {
            int parentIndex = (cur_index - 1) / 2;
            if (v[parentIndex] < v[cur_index])
            {
                swap(v[parentIndex], v[cur_index]);
                cur_index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "-> ";
    }
    return 0;
}