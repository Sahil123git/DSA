#include <bits/stdc++.h>
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
class Stack
{
    Node *dummy = new Node(-1);
    Node *mid = dummy;
    int size = 0;

public:
    void Push(int ele)
    {
        Node *orgNxt = dummy->next;
        dummy->next = new Node(ele);

        Node *newNode = dummy->next;
        newNode->prev = dummy;

        if (orgNxt != NULL)
        {
            newNode->next = orgNxt;
            orgNxt->prev = newNode;
        }
        if (size % 2 == 0)
        {
            if (mid == dummy)
            {
                mid = mid->next;
            }
            else
            {
                mid = mid->prev;
            }
            // cout << "her";
            // cout << mid->data << " ehe " << endl;
        }
        // cout << size << " sz " << endl;
        size++;
    }

    void Pop()
    {
        if (dummy->next == NULL)
        {
            cout << "UnderFlow";
            return;
        }

        Node *orgNxt = dummy->next;
        if (orgNxt->next != NULL)
        {
            Node *orgNxtNxt = orgNxt->next;
            orgNxtNxt->prev = dummy;
        }
        Node *del = dummy->next;
        dummy->next = dummy->next->next;

        if (size & 1)
        {
            if (mid->next == NULL)
            {
                mid = mid->prev;
            }
            else
            {
                mid = mid->next;
            }
        }
        delete (del);
        size--;
    }

    void Top()
    {
        if (dummy->next != NULL)
        {
            cout << dummy->next->data << endl;
        }
    }

    void getMid()
    {
        // if (mid == NULL)
        // {
        //     cout << "h";
        // }
        if (mid == dummy)
        {
            cout << "No Node is present" << endl;
            return;
        }
        cout << mid->data << endl;
    }
};

int main()
{
    Stack stk;
    stk.Push(1);
    stk.Push(2);
    stk.Pop();

    // stk.Top();

    stk.Push(3);
    stk.Push(13);
    stk.Push(14);
    stk.Push(15);
    stk.Pop();
    stk.Pop();
    stk.Pop();
    stk.Pop();
    stk.Pop();
    stk.Push(16);
    stk.Push(17);

    // stk.Push(1);
    // stk.Push(2);
    // stk.Push(3);
    // stk.Push(4);

    // stk.Pop();
    // stk.Pop();
    // stk.Pop();
    // stk.Pop();

    // stk.Push(4);
    // stk.Push(5);
    stk.getMid();

    // stk.Top();
}