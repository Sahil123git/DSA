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

Node *insert_end(Node *head, int ele)
{
    if (head == NULL)
    {
        Node *temp = new Node(ele);
        head = temp;
        return head;
    }
    Node *temp1 = head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = new Node(ele);
    return head;
}
Node *merge_LL(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    Node *c;
    if (head1->data < head2->data)
    {
        c = head1;
        c->next = merge_LL(head1->next, head2);
    }
    else
    {
        c = head2;
        c->next = merge_LL(head1, head2->next);
    }
    return c; //this c will get add all values
}
int main()
{
    Node *head = NULL;
    int n;
    cin >> n;
    while (n--)
    {
        int ele;
        cin >> ele;
        head = insert_end(head, ele);
    }
    Node *head1 = NULL;
    int n1;
    cin >> n1;
    while (n1--)
    {
        int ele;
        cin >> ele;
        head1 = insert_end(head1, ele);
    }
    head = merge_LL(head, head1);
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}
