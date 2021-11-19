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
Node *sorted_insert(Node *head, int ele)
{
    Node *temp = new Node(ele);
    Node *cur = head;
    if (head == NULL)
    {
        return temp;
    }
    if (head->data > ele)
    {
        temp->next = head;
        return temp;
    }
    while (cur != NULL)
    {
        if (cur->next == NULL) //this is the condition when we are on last ele
        {
            cur->next = temp;
            break;
        }
        else if (ele < cur->next->data)
        {
            temp->next = cur->next;
            cur->next = temp;
            break;
        }
        cur = cur->next;
    }
    return head;
} 
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(40);

    head->next = temp1;
    temp1->next = temp2;
    int ele;
    cin >> ele;
    Node *temp3 = NULL;
    temp3 = sorted_insert(head, ele);
    while (temp3 != NULL)
    {
        cout << temp3->data << " | ";
        temp3 = temp3->next;
    }
}