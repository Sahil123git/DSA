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

Node *Rec_rev(Node *head)
{
    if (head->next == NULL or head == NULL) //head==NULL for checking if they have given noly 1 linked list
    {
        return head;
    }
    Node *R_head = Rec_rev(head->next);
    head->next->next = head;
    head->next = NULL;
    // cout << R_head->data << endl;//this will tell Rhead will only contain Last ele
    return R_head; //Rhead will always point to last data of linked list
}
void Iterate(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    Node *temp3 = new Node(40);

    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;

    Node *Rec_node = Rec_rev(head);
    Iterate(Rec_node);
}