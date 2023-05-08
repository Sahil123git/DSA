#include <bits/stdtr1c++.h>
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

class Queue
{
public:
    Node *dummy = new Node(-1);
    Node *ptr = dummy;
    void Push(int ele) // always adding nodes after ptr
    {
        ptr->next = new Node(ele);
        ptr = ptr->next;
    }

    void Pop()
    {
        if (dummy->next == NULL)
        {
            cout << "UnderFlow" << endl;
            return;
        }

        Node *nxt = dummy->next;
        dummy->next = dummy->next->next;
        nxt = NULL;
        delete (nxt);
    }
    int Front()
    {
        if (dummy->next == NULL)
        {
            cout << "No node is present";
            return -1;
        }
        return dummy->next->data;
    }
};

int main()
{
    int n;
    cin >> n;

    Queue qu;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;

        qu.Push(ele);
    }

    qu.Pop();
    qu.Pop();
    cout << qu.Front();
}