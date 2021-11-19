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
Node *insert(Node *head, int x)
{
    Node *temp_head = new Node(x);
    temp_head->next = head;
    cout << temp_head->data << " ";
    return temp_head;
}
int main()
{
    Node *head = NULL;
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);

    while (head != NULL) // |40|address_of_30|  |30|address_of_20|   |20|NULL|
    {                    //this we got after inserting in beginning
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}