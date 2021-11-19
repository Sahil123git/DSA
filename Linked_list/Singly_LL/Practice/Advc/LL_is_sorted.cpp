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

void displayList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
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

bool isSorted(Node *head)
{
    Node *temp = head;
    int count = 0, count1 = 0, tot_count = 0;
    while (temp->next != NULL)
    {
        if (temp->data <= temp->next->data)
        {
            count++;
            // cout << temp->data << " " << temp->next->data << endl;
        }
        if (temp->data >= temp->next->data)
        {
            count1++;
        }
        temp = temp->next;
        tot_count++;
    }
    // cout << count << " " << count1 << " " << tot_count << endl;
    if (count == (tot_count) || count1 == (tot_count))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// { Driver Code Starts.

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
        cout << isSorted(head) << endl;
    }
    return 0;
} // } Driver Code Ends