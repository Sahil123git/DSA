#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *insert_end(Node *head, int ele)
{
    if (head == NULL)
    {
        Node *temp = new Node(ele);
        head = temp;
        return head;
    }
    Node *temp1 = head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = new Node(ele); //can directly use this
    return head;
}

int main()
{
    Node *head = NULL;
    int n;
    cin >> n;
    while (n--)
    {
        int ele;
        cin >> ele;
        head = insert_end(head, ele);
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}
