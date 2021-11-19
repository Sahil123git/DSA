#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
Node *OPT_Rev(Node *head)
{
    Node *prev = NULL;
    Node *cur = head;
    Node *temp;
    while (cur != NULL)
    {
        temp = cur->next;
        cur->next = prev;

        prev = cur;
        cur = temp;
    }
    // cout << prev->data << " g ";
    head = prev;
    return head;
}
void Rec_traversal(Node *head)
{
    Node *cur = head;
    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}
int main()
{
    Node *head = new Node(10);
    Node *temp = new Node(20);
    Node *temp1 = new Node(30);
    Node *temp2 = new Node(40);

    head->next = temp;
    temp->next = temp1;
    temp1->next = temp2;

    Rec_traversal(head);
    Node *Rec_Node = OPT_Rev(head);
    Rec_traversal(Rec_Node);
}