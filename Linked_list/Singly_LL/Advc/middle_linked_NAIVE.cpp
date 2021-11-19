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

Node *Middle(Node *head)
{
    int count = 0;
    Node *Temp = head;
    for (Temp = head; Temp != NULL; Temp = Temp->next)
    {
        count++; //for calculating size
    }
    Temp = head;
    // cout << count << endl;
    for (int i = 0; i != count / 2; i++)
    {
        // cout << head->data;
        head = head->next;
        // cout << i;
    }
    return head;
}
int main()
{
    Node *head = new Node(10);
    Node *temp = new Node(20);
    Node *temp1 = new Node(30);
    Node *temp2 = new Node(40);

    head->next = temp;
    temp->next = temp1;
    temp1->next = temp2;

    Node *mid = Middle(head);
    cout << mid->data;
    return 0;
}