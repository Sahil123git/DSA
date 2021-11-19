#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void displayList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *deleteAtPosition(Node *head, int pos)
{
    //Your code here
    int count = 1;
    Node *temp = head;
    if (pos == 1)
    {
        Node *temp1 = temp;
        temp = temp->next;
        temp1 = NULL;
        delete (temp1);
        return temp;
    }
    while (temp != NULL)
    {
        count++;
        if (count >= pos)
        {
            break;
        }
        temp = temp->next;
    }
    Node *temp1 = temp->next;
    temp->next = temp->next->next;
    delete (temp1);
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

        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        int pos;
        cin >> pos;
        head = deleteAtPosition(head, pos);
        displayList(head);
        cout << endl;
    }
    return 0;
} // } Driver Code Ends