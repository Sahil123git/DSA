#include <bits/stdc++.h>
using namespace std;
class LinkedList
{
public:
    int data;
    LinkedList *next;
    LinkedList(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class Stack
{
    LinkedList *dummy = new LinkedList(-1);

public:
    void push(int ele)
    {
        LinkedList *node = dummy->next;
        dummy->next = new LinkedList(ele);
        dummy->next->next = node;
    }
    void pop()
    {
        if (dummy->next == NULL)
        {
            cout << "No node is present";
        }
        else
        {
            dummy->next = dummy->next->next;
        }
    }

    int top()
    {
        if (dummy->next == NULL)
        {
            return -1;
        }
        else
        {
            return dummy->next->data;
        }
    }
};
int main()
{
    Stack stk;
    stk.push(1);
    stk.push(3);
    stk.pop();
    stk.push(2);
    cout << stk.top() << endl;
    stk.push(5);
    stk.pop();
    stk.pop();
    cout << stk.top();
}