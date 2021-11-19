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

// function to display the linked list
void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *insertInMiddle(Node *head, int x);

int main()
{
    int T, n, x;
    cin >> T;
    while (T--)
    {
        cin >> n >> x;

        struct Node *head = new Node(x);
        struct Node *tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> x;
            tail->next = new Node(x);
            tail = tail->next;
        }

        cin >> x;
        head = insertInMiddle(head, x);
        display(head);
    }
    return 0;
}
//Function to insert a node in the middle of the linked list.
Node *insertInMiddle(Node *head, int x)
{
    Node *new_node = new Node(x);
    Node *slow = head;
    Node *fast = head;
    Node *temp = head;
    Node *save1 = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        save1 = slow;
        slow = slow->next;
    }
    if (count % 2 == 0)
    {
        new_node->next = save1->next;
        save1->next = new_node;
        // new_node->next = save;
    }
    else
    {
        new_node->next = slow->next;
        slow->next = new_node;
    }
    return head;
}