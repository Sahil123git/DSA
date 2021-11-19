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

Node *Reverse(Node *head)
{
    vector<int> v;
    for (Node *cur = head; cur != NULL; cur = cur->next)
    {
        v.push_back(cur->data);
    }
    for (Node *cur = head; cur != NULL; cur = cur->next)
    {
        cur->data = v.back();
        v.pop_back();
    }
    return head;
}

int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    // Node *temp3 = new Node(40);

    head->next = temp1;
    temp1->next = temp2;
    // temp2->next = temp3;

    Node *rec_node = Reverse(head);
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}