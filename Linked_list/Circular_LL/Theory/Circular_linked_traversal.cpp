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
void traversal1(Node *head)
{
    Node *temp = head;
    while (temp->next != head) //if keep head!=head it will not print ll
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}
void traversal3(Node *head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
void traversal2(Node *head)
{
    Node *temp = head;
    cout << temp->data << " "; //printing ll because it will not start from 1
    for (Node *temp1 = head->next; temp1 != head; temp1 = temp1->next)
    {
        cout << temp1->data << " ";
    }
    cout << endl;
}
int main()
{
    Node *head = new Node(10);
    Node *temp = new Node(20);
    Node *temp1 = new Node(30);

    head->next = temp;
    temp->next = temp1;
    temp1->next = head;

    traversal1(head);
    traversal2(head);
    traversal3(head);
    return 0;
}