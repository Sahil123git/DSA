#include <iostream>
#include <vector>
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
void addAtHead(Node *dummy, int data)
{
    Node *nxt = dummy->next;
    dummy->next = new Node(data);
    dummy->next->next = nxt;
}

void popNode(Node *dummy)
{
    if (dummy->next == NULL)
    {
        cout << "No new node is entered " << endl;
        return;
    }

    dummy->next = dummy->next->next;
}

void printD(Node *dummy)
{
    Node *iter = dummy->next;
    while (iter != NULL)
    {
        cout << iter->data << " ";
        iter = iter->next;
    }
}

int main()
{
    Node *dummy = new Node(-1);

    for (int i = 0; i < 5; i++)
    {
        addAtHead(dummy, i);
    }
    popNode(dummy);
    popNode(dummy);

    printD(dummy);
}