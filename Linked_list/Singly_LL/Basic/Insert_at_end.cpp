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
    head->next = temp_head;
    return temp_head;
}
int main()
{
    Node *head = new Node(10);
    Node *temp = new Node(20);
    head->next = temp;

    temp = insert(temp, 30);
    temp = insert(temp, 40);

    while (head != NULL) // |40|address_of_30|  |30|address_of_20|   |20|NULL|
    {                    //this we got after inserting in beginning
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}