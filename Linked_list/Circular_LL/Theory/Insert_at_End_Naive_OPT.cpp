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
Node *insert_end(Node *head, int ele) //------------NAIVE APPROACHF
{
    Node *new_val = new Node(ele);
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = new_val;
    new_val->next = head;
    return head;
}
Node *insert_opt(Node *head, int ele) //--------------OPT APPROACH
{
    if (head == NULL)
    {
        Node *temp = new Node(ele);
        temp->next = temp;
    }
    Node *temp = head;
    Node *new_val = new Node(ele);

    new_val->next = head->next; //Inserting the extra node
    head->next = new_val;

    int data; //swapping data of both nodes
    data = temp->data;
    temp->data = new_val->data;
    new_val->data = data;

    head = new_val;
    return head;
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
    Node *temp12 = new Node(30);

    head->next = temp;
    temp->next = temp12;
    temp12->next = head;

    int ele;
    cin >> ele;
    Node *new_head = insert_end(head, ele);
    traversal(new_head);

    Node *head1 = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp11 = new Node(30);

    head1->next = temp1;
    temp1->next = temp11;
    temp11->next = head1;

    int ele1;
    cin >> ele1;
    Node *new_head1 = insert_end(head1, ele1);
    traversal(new_head1);
}
