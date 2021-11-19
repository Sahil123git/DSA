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
Node *insert_begin(Node *head, int ele)
{
    Node *temp = new Node(ele);
    if (head == NULL)
    {
        return temp;
    }
    temp->next = head;
    head->prev = temp; //IMP step for doubly LL
    head = temp;
    return head;
}
int main()
{
    Node *head = new Node(20);
    Node *temp1 = new Node(30);
    Node *temp2 = new Node(40);
    Node *temp3 = new Node(50);

    head->next = temp1;
    temp1->next = temp2;
    temp1->prev = head;
    temp2->next = temp3;
    temp2->prev = temp1;
    temp3->next = NULL;

    int ele;
    cin >> ele;
    Node *temp = insert_begin(head, ele);
    traversal(temp);

    return 0;
}
