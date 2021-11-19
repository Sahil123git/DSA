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
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *del_last(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete (temp);
    return head;
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    Node *temp3 = new Node(40);

    head->next = temp1;

    temp1->next = temp2;
    temp1->prev = head;

    temp2->next = temp3;
    temp2->prev = temp1;

    temp3->prev = temp2;
    temp3->next = NULL;

    Node *del_tra = del_last(head);
    traversal(head);
    return 0;
}
