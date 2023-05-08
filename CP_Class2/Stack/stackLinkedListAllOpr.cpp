#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev, *next;
    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class Stack
{

    Node *dummy = NULL, *mid = NULL;

public:
    int size = 0;

    void addNode(int data)
    {
        if (dummy == NULL)
        {
            dummy = new Node(-1);
        }
        Node *dummyNxt = dummy->next;
        Node *newNode = dummy->next = new Node(data);
        if (dummyNxt != NULL)
        {
            dummyNxt->prev = newNode;
        }
        newNode->prev = dummy;
        newNode->next = dummyNxt;
    }

    int getMid()
    {
        if (mid == NULL)
        {
            return -1;
        }
        return mid->data;
    }

    int _size()
    {
        return size;
    }

    void _push(int data) // inserting ele at head
    {
        // cout << "here";
        addNode(data);
        if (mid == NULL)
        {
            mid = dummy->next;
        }
        size++;
        if (size % 2 == 0)
        {
            mid = mid->prev;
        }
        else
        {
            // no change in odd size
        }
    }

    void _pop()
    {
        if (dummy->next == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        if (size == 1)
        {
            cout << "Now there is no mid";
            dummy->next = NULL;
            mid = NULL;
            size--;
            return;
        }

        if (size % 2 == 0)
        {
            mid = mid->next;
        }
        // cout << "here";

        dummy->next = dummy->next->next;
        dummy->next->prev = dummy;
        size--;
    }
    void popMid()
    {
        Node *nMid;
        if (dummy->next == NULL || dummy->next->next == NULL)
        {
            cout << "No mid is there in stack becoz stack is empty" << endl;
            mid = NULL;
            dummy->next = NULL;
            return;
        }
        if (size % 2 != 0)
        {
            nMid = mid->prev;
            cout << nMid->data << " new mid" << endl;
        }
        else
        {
            nMid = mid->next;
        }
        mid->next->prev = mid->prev;
        mid->prev->next = mid->next;
        mid = nMid;
        size--;
        // cout << mid->next->data << " " << mid->prev->data << endl;
        // cout << "mid of stack is " << mid->data << endl;
    }

    void display()
    {
        Node *iter = dummy->next;

        while (iter != NULL)
        {
            cout << iter->data << " ";
            iter = iter->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack stk;
    // cout << "where";
    stk._push(2);
    stk._push(3);
    stk._push(4);
    stk._pop();
    stk._push(5);
    stk._push(6);

    cout << "stack size is " << stk._size() << endl;
    stk.popMid();
    stk.popMid();
    stk.popMid();
    stk.popMid();
    cout << "Mid ele of stack is " << stk.getMid() << endl;
    // cout << " after removing pop " << stk.popMid() << endl;

    stk.display();
}