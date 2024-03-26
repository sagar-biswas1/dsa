// #include <bits/stdc++.h>
// using namespace std;

// class Node
// {
// public:
//     int val;
//     Node *left;
//     Node *right;
//     Node(int val)
//     {
//         this->val = val;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// Node *btreeInput()
// {
//     int val;
//     cin >> val;
//     if (val == -1)
//         return NULL;

//     Node *root = new Node(val);
//     queue<Node *> q;
//     q.push(root);

//     while (!q.empty())
//     {
//         Node *f = q.front();
//         q.pop();

//         int l, r;
//         cin >> l >> r;

//         if (l != -1)
//         {
//             f->left = new Node(l);
//             q.push(f->left);
//         }
//         if (r != -1)
//         {
//             f->right = new Node(r);
//             q.push(f->right);
//         }
//     }

//     return root;
// }

// void accessLeafNodes(Node *root, stack<int> &st) {
//   if (root == NULL) {
//     return;
//   }
//   if (!root->left && !root->right) {
//     st.push(root->val);
//   } else {
//     accessLeafNodes(root->left, st);
//     accessLeafNodes(root->right, st);
//   }
// }
// int main()
// {
//     Node *root = btreeInput();
//     stack<int> st;
//     accessLeafNodes(root, st);
//     while (!st.empty())
//     {
//         cout << st.top() ;
//         st.pop();
//         if(st.size()){
//             cout<<" ";
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node(int val) {
    this->val = val;
    this->left = NULL;
    this->right = NULL;
  }
};

Node* btreeInput() {
  int val;
  cin >> val;
  if (val == -1) return NULL;

  Node* root = new Node(val);
  queue<Node*> q;
  q.push(root);

  while (!q.empty()) {
    Node* f = q.front();
    q.pop();

    int l, r;
    cin >> l >> r;

    if (l != -1) {
      f->left = new Node(l);
      q.push(f->left);
    }
    if (r != -1) {
      f->right = new Node(r);
      q.push(f->right);
    }
  }

  return root;
}

void accessLeafNodes(Node* root, stack<int>& st) {
  if (root == NULL) {
    return;
  }
  if (!root->left && !root->right) {
    st.push(root->val);
  } else {
    accessLeafNodes(root->left, st); // Reverse traversal for descending order
    accessLeafNodes(root->right, st);
  }
}


void sortStack(stack<int> &s) {
    // Transfer elements from stack to vector
    vector<int> v;
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }

    // Sort the vector in des order
    sort(v.begin(), v.end(), greater<int>());

    // Transfer elements from vector back to stack
    for (int i = v.size() - 1; i >= 0; --i) {
        s.push(v[i]);
    }
}

int main() {
  Node* root = btreeInput();
  stack<int> st;
  accessLeafNodes(root, st);
sortStack(st);

  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }

  return 0;
}
