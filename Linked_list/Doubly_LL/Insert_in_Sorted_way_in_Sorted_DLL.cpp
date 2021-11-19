// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node *getNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

bool isChecked(Node *head)
{
    int lengthF = 0;
    int lengthB = 0;
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
        lengthF++;
    }

    while (temp->prev)
    {
        temp = temp->prev;
        lengthB++;
    }

    return lengthF == lengthB;
}

Node *sortedInsert(Node *head, int x);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        struct Node *new_node = NULL;
        int n, tmp, x;
        cin >> n;
        Node *head = NULL, *tail = NULL;
        cin >> x;
        head = getNode(x);
        tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> x;
            Node *temp = getNode(x);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        cin >> x;
        head = sortedInsert(head, x);

        if (isChecked(head))
            printList(head);
        else
            cout << "The node has not been inserted correctly. Please fix the prev and next pointers";
        cout << endl;
    }
    return 0;
}

Node *sortedInsert(Node *head, int x)
{
    Node *new_ele = getNode(x);
    Node *temp = head;
    if (head == NULL)
    {
        return new_ele;
    }
    if (temp->data > x) //for checking if it is smaller than 1st ele
    {
        new_ele->next = temp;
        temp->prev = new_ele;
        return new_ele;
    }

    while (temp->next != NULL) //for all middle ele
    {
        if (temp->data > x)
        {
            new_ele->prev = temp->prev;
            temp->prev = new_ele;
            new_ele->next = temp;
            new_ele->prev->next = new_ele;
            return head;
        }
        temp = temp->next;
    }
    if (temp->data > x) //if smaller than 2nd last ele
    {
        new_ele->prev = temp->prev;
        temp->prev = new_ele;
        new_ele->next = temp;
        new_ele->prev->next = new_ele;
    }
    else //if greater than last ele
    {
        temp->next = new_ele;
        new_ele->prev = temp;
    }
    return head;
}