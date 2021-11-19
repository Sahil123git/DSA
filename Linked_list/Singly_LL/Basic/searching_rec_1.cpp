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
int print(Node *head, int key)
{
    static int count = 0;
    if (head == NULL)
    {
        return 0;
    }
    else if (key == head->data)
    {
        return count;
    }
    count++;
    // cout << head->data << " ";
    return print(head->next, key);
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);

    head->next = temp1;
    temp1->next = temp2;
    int key = 9;
    cout << print(head, key);
}