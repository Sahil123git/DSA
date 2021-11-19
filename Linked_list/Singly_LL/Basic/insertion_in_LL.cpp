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
// void insert_end(Node *&head, int ele)
// {
//     if (head == NULL)
//     {
//         Node *temp = new Node(ele);
//         head = temp;
//         return;
//     }
//     Node *temp1 = head;
//     while (temp1->next != NULL)
//     {
//         temp1 = temp1->next;
//     }
//     Node *temp = new Node(ele);
//     temp1->next = temp;
// }
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
    temp1->next = new Node(ele);
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
