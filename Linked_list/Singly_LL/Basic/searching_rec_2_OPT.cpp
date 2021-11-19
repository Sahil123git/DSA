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
    if (head == NULL)
    {
        return -1;
    }
    else if (head->data == key)
    {
        return 1; //it will return to prev func
    }
    else
    {
        int res = print(head->next, key);
        if (res == -1)
        {
            return -1;
        }
        else
        {
            return (res + 1);
        }
    }
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);

    head->next = temp1;
    temp1->next = temp2;
    int key;
    cin >> key;
    cout << print(head, key);
}