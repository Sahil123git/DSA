// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
int maximum(struct Node *head);
int minimum(struct Node *head);
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
        cout << maximum(head) << " d " << minimum(head) << endl;
    }
    return 0;
} // } Driver Code Ends

int maximum(Node *head)
{
    //Your code here
    Node *temp = head;
    int maxi = -1;
    while (temp != NULL)
    {
        if (maxi < temp->data)
        {
            maxi = temp->data;
        }
        temp = temp->next;
    }
    // cout<<maxi<<endl;
    return maxi;
}

int minimum(Node *head)
{
    //Your code here
    Node *temp = head;
    int mini = 10000;
    while (temp != NULL)
    {
        if (mini > temp->data)
        {
            mini = temp->data;
        }
        temp = temp->next;
    }
    return mini;
}