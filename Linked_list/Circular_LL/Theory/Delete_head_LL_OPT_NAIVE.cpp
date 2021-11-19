#include <iostream>
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
Node *del_begin(Node *head) //----------NAIVE APPROACH
{
    if (head == NULL)
    {
        return NULL;
    }
    else if (head->next == head)
    {
        return NULL;
        delete (head);
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    Node *new_head = temp->next;
    temp->next = head->next;
    delete (new_head);
    return temp->next;
}
Node *del_begin1(Node *head) //----------OPT APPROACH
{
    if (head == NULL)
    {
        return NULL;
    }
    else if (head->next == head)
    {
        return NULL;
        delete (head);
    }
    Node *temp = head;
    head->data = head->next->data;
    Node *temp1 = head->next;
    head->next = head->next->next;
    delete (temp1);
    return temp;
}
void traversal(Node *head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main()
{
    Node *head = new Node(10);
    Node *temp = new Node(20);
    Node *temp13 = new Node(30);
    Node *temp12 = new Node(40);

    head->next = temp;
    temp->next = temp13;
    temp13->next = temp12;
    temp12->next = head;

    Node *new_head = del_begin(head);
    traversal(new_head);

    Node *head1 = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp11 = new Node(30);

    head1->next = temp1;
    temp1->next = temp11;
    temp11->next = head1;

    Node *new_head1 = del_begin1(head1);
    traversal(new_head1);
}
