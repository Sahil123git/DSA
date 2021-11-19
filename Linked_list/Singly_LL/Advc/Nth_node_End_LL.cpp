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
Node *nth_fun(Node *temp, int n)
{
    Node *cur = temp;
    int total = 0;
    for (; cur != NULL; cur = cur->next)
    {
        total++;
    }
    if (total < n)
    {
        return NULL;
    }
    n = total - n;
    cout << n << " ";
    for (int i = 0; i < n ; i++)
    {
        temp = temp->next;
    }
    return temp;
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
    int n;
    cin >> n;
    // n = 3;
    Node *nth_node = nth_fun(head, n);
    cout << nth_node->data << " ";
}