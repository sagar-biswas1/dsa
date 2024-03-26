#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
};

void Reverse(Node *&head,Node *crr){
    if(crr->next==NULL){
        head=crr;
        return;
    }
    Reverse(head,crr->next);
    crr->next->next=crr;
    crr->next=NULL;
    // cout<<head->val<<"";
}

int main()
{

    Node *head = NULL;
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,8);
// cout<<"Insert";
Reverse(head,head);
    while(head !=NULL){
        cout<<" "<<head->val<<endl;
        head=head->next;
    }
    return 0;
}