#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *newNode(int data)
{
    Node *temp = new Node(data);

    return temp;
}
void displayList(Node *head)
{
    while (head->next)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data;
    cout << endl;

    while (head->prev)
    {
        cout << head->data << " ";
        head = head->prev;
    }
    cout << head->data;
}
Node *deleteTail(Node *head)
{
    Node *temp = head;
    if (temp->next == NULL)
    {
        Node *del_ele = temp->next;
        delete (del_ele);
        return NULL;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *del_ele = temp->next;
    temp->next->prev = NULL;
    temp->next = NULL;
    delete (del_ele);
    return head;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Node *head = NULL, *tail = NULL;
        int x;
        cin >> x;
        head = newNode(x);
        tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> x;
            Node *temp = newNode(x);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        head = deleteTail(head);
        displayList(head);
        cout << endl;
    }
    return 0;
}