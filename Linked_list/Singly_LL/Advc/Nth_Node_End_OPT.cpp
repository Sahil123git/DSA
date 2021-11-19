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
    // cout << "FD";
    Node *first = temp;
    Node *second = temp;
    for (int i = 0; i < n; i++)
    {
        if (second == NULL) //if limit of n crosses temp length
        {
            return NULL; //it wll return NULL
        }
        second = second->next;
    }
    // cout << second->data << " ";
    while (second != NULL) //it will not work for last from end
    {
        second = second->next;
        first = first->next;
    }
    return first;
}
int main()
{
    // cout << "FD";
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    Node *temp3 = new Node(40);

    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    int n;
    cin >> n;
    // n = 4;
    Node *nth_node = nth_fun(head, n);
    cout << nth_node->data << " ";
}