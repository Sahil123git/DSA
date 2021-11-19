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
    temp1->next = new Node(ele);
    return head;
}

Node *K_rev(Node *head, int key) //rec approach
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *cur = head;
    Node *prev = NULL;
    Node *temp = NULL;
    int count = 0;
    while (cur != NULL && count < key) //this reversing k ele of ll
    {
        temp = cur->next;
        cur->next = prev;

        prev = cur;
        cur = temp;
        count++;
    }
    if (cur != NULL)
    {
        head->next = K_rev(cur, key); //this will point head of this to next
    }                                 //returning LL
    return prev;                      //this prev will remain head for all rec calls
}
int main()
{
    Node *head = NULL;
    int n;
    cin >> n;
    int key;
    cin >> key;
    while (n--)
    {
        int ele;
        cin >> ele;
        head = insert_end(head, ele);
    }
    head = K_rev(head, key);
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}
