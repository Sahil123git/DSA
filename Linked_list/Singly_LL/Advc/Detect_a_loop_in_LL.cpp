#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

class Solution
{
public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node *head)
    {
        // your code here
        if (head == NULL)
        {
            return 0;
        }
        Node *temp1 = head;
        Node *temp2 = head;
        while (temp2 != NULL && temp2->next != NULL) //this will cond will check whether there is a loop or not
        {
            temp1 = temp1->next;
            temp2 = temp2->next->next;
            if (temp1 == temp2)
            {
                return 1;
            }
        }
        return 0;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num;
        cin >> n;

        Node *head, *tail;
        cin >> num;
        head = tail = new Node(num);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin >> pos;
        loopHere(head, tail, pos);

        Solution ob;
        if (ob.detectLoop(head))
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
