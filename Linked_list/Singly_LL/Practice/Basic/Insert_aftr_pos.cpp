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

void insertAtPosition(Node *head, int pos, int data)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (count >= pos)
    {
        Node *New_node = new Node(data);
        Node *temp1 = head;
        Node *temp2 = head;
        int count1 = 1;
        while (count1 < pos)
        {
            temp1 = temp1->next;
            count1++;
        }
        New_node->next = temp1->next;
        temp1->next = New_node;
    }
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
        int d;
        cin >> d;
        insertAtPosition(head, pos, d);
        displayList(head);
        cout << endl;
    }
    return 0;
} // } Driver Code Ends