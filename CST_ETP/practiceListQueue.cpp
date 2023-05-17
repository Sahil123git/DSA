#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int node;
    Node *next;
    Node(int node)
    {
        this->node = node;
        next = NULL;
    }
};

Node *dummy, *lst;
class LinkedList
{
public:
    LinkedList()
    {
        dummy = new Node(-1);
        lst = dummy;
    }
    void addNode(int val)
    {
        // if (dummy->next == NULL)
        // {
        //     dummy->next = new Node(val);
        // }
        // else
        // {
        //     while (dummy->next != NULL)
        //     {
        //         dummy = dummy->next;
        //     }
        //     dummy->next = new Node(val);
        // }

        lst->next = new Node(val);
        lst = lst->next;
    }

    void removeNode()
    {
        if (dummy->next == NULL)
        {
            cout << " Linked List is empty \n";
            lst = dummy;
        }
        else
        {
            dummy->next = dummy->next->next;
        }
    }
    void front()
    {
        if (dummy->next != NULL)
        {
            cout << dummy->next->node << endl;
        }
    }
    void showNodes()
    {
        Node *temp = dummy->next;
        while (temp != NULL)
        {
            cout << temp->node << " ";
            temp = temp->next;
        }
    }
};
int main()
{
    LinkedList head;
    head.addNode(1);
    head.addNode(2);
    head.addNode(3);

    // head.removeNode();
    head.removeNode();
    head.front();
    head.removeNode();
    // head.removeNode();
    // head.removeNode();

    head.addNode(4);

    head.showNodes();
}
