// { Driver Code Starts
//Initial Template for C++

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

Node *newNode(int data)
{
    Node *temp = new Node(data);

    return temp;
}

void displayList(Node *head)
{
    Node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
}

// } Driver Code Ends
//User function Template for C++

/*
struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
        
};
*/
void insertAtPosition(Node *head, int pos, int data)
{
    //Your code here
    int size = 0;
    Node *check_size = head;
    do
    {
        check_size = check_size->next;
        size++;
    } while (check_size != head);

    if (size < pos)
    {
        return;
    }

    int count = 1;
    Node *temp = head;
    while (count < pos)
    {
        temp = temp->next;
        count++;
    }
    Node *new_data = new Node(data);

    new_data->next = temp->next;
    temp->next = new_data;
}

// { Driver Code Starts.

void makeCircular(Node *head)
{
    Node *temp = head;

    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = head;
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
        head = new Node(x);
        tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> x;
            tail->next = new Node(x);
            tail = tail->next;
        }

        int pos;
        cin >> pos;

        int data;
        cin >> data;

        makeCircular(head);

        insertAtPosition(head, pos, data);

        displayList(head);

        cout << endl;
    }
    return 0;
} // } Driver Code Ends