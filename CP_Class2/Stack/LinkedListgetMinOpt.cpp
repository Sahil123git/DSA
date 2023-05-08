#include <iostream>
#include <climits>
using namespace std;
class Node
{
public:
    Node *next;
    int data;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Stack
{
    Node *dummy;
    int Min, size;

public:
    Stack()
    {
        dummy = addNode(-1);
        size = 0;
        Min = INT_MAX;
    }
    Node *addNode(int val)
    {
        Node *node = new Node(val);
        return node;
    }

    void _push1(int ele)
    {
        Node *fstNode = addNode(ele);
        fstNode->next = dummy->next;
        dummy->next = fstNode;
    }

    void _push(int ele)
    {
        if (ele <= Min)
        {
            _push1(Min);
            Min = ele;
        }

        _push1(ele);
        size++;
    }
    void _pop1()
    {
        Node *delNode = dummy->next;
        dummy->next = dummy->next->next;
        delete (delNode);
    }
    void _pop()
    {
        if (dummy->next == NULL)
        {
            cout << "No ele remaining " << endl;
            return;
        }
        else if (_top() == Min)
        {
            _pop1();
            Min = dummy->next->data;
        }
        _pop1();
        size--;
    }
    int _top()
    {
        if (dummy->next == NULL)
        {
            cout << "no top ele" << endl;
            return -1;
        }
        return dummy->next->data;
    }
    int getMin()
    {
        return Min;
    }
    int stackSize()
    {
        return size;
    }
};

int main()
{
    Stack stk;
    stk._push(-5);
    stk._push(-5);
    stk._push(7);
    cout << stk._top() << endl;
    stk._push(2);
    stk._pop();
    stk._pop();
    stk._pop();
    cout << stk.getMin() << endl;
    cout << "size of stack " << stk.stackSize();
}