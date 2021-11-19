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

void Iterate(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *Rem_dup(Node *head)
{
    Node *cur = head;

    while (cur != NULL && cur->next != NULL)
    {
        if (cur->data == cur->next->data)
        {
            Node *temp = cur->next;
            cur->next = cur->next->next;
            delete (temp);
            continue; //used continue statement otherwise it will not remove which are
            // duplicate are present more than once
        }

        cur = cur->next;
    }
    return head;
}
int main()
{
    //  Node *head = NULL;
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(20);
    Node *temp3 = new Node(20);
    Node *temp4 = new Node(20);

    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;

    Node *Rec_node = Rem_dup(head);
    Iterate(Rec_node);
}