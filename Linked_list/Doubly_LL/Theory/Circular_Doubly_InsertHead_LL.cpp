#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
void traversal(Node *head)
{
    Node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}
Node *insert_head(Node *head, int ele)
{
    if (head == NULL)
    {
        Node *new_head = new Node(ele);
        new_head->next = new_head;
        new_head->prev = new_head;
    }
    Node *New_ele = new Node(ele);
    Node *temp = head;

    New_ele->prev = temp->prev;
    New_ele->next = temp;
    temp->prev->next = New_ele;
    temp->prev = New_ele;

    return New_ele;
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    Node *temp3 = new Node(40);

    head->next = temp1;
    head->prev = temp3;

    temp1->next = temp2;
    temp1->prev = head;

    temp2->next = temp3;
    temp2->prev = temp1;

    temp3->prev = temp2;
    temp3->next = head;

    Node *insert_h = insert_head(head, 5);
    traversal(insert_h);
    return 0;
}
