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
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}
class Solution
{
public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x)
    {
        Node *temp1 = new Node(x);
        temp1->next = head;
        // cout << "beg " << temp1->data << endl;
        return temp1;
    }

    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)
    {
        Node *temp2 = new Node(x);
        if (head == NULL)
        {
            return temp2;
        }
        Node *cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = temp2;
        // cout << "end " << head->data << " " << head->next->data << " " << head->next->next->data << endl;
        return head;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        struct Node *head = NULL;
        for (int i = 0; i < n; ++i)
        {
            int data, indicator;
            cin >> data;
            cin >> indicator;
            Solution obj;
            if (indicator)
                head = obj.insertAtEnd(head, data);
            else
                head = obj.insertAtBegining(head, data);
        }
        printList(head);
    }
    return 0;
}

// } Driver Code Ends