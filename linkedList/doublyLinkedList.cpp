#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

int main()
{
    Node *head = new Node(1);
    Node *a = new Node(2);
    Node *b = new Node(3);
    Node *c = new Node(4);
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = b;
    // 1,2,3,4
    // 1,2,3,4,1,2
    // 1,3,4,4,2

    Node *f = head;
    Node *s = head;
    while (f != NULL && f->next != NULL)
    {
        f = f->next->next;
        s = s->next;
        if (s == f)
        {
            cout << "detected for" << s->val << " and " << f->val << endl;
            break;
        }
    }
    return 0;
}