#include <bits/stdc++.h>
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
public:
    int topEle = -1;
    Node *dummy = new Node(-1);
    stack<int> stk;
    int minEle = INT_MAX;
    void AddAtHead(int ele) // inserting new ele always after dummy
    {
        Node *dumNext = dummy->next;
        dummy->next = new Node(ele);
        dummy->next->next = dumNext;
        if (ele <= minEle)
        {
            minEle = ele;
            stk.push(minEle);
        }
    }

    int Top()
    {
        if (dummy->next == NULL)
        {
            return -1;
        }
        return dummy->next->data;
    }

    void Pop()
    {
        if (dummy->next == NULL)
        {
            cout << "No node is present" << endl;
            return;
        }
        if (minEle == Top())
        {
            stk.pop();
            if (stk.empty())
            {
                minEle = INT_MAX;
            }
            else
            {
                minEle = stk.top();
            }
        }
        Node *nxt = dummy->next;
        dummy->next = dummy->next->next;
        nxt = NULL;
    }
    void print()
    {
        for (Node *temp = dummy->next; temp != NULL; temp = temp->next)
        {
            cout << temp->data << " ";
        }
    }
    int getMin()
    {
        return minEle;
    }
};
int main()
{
    int n;
    cin >> n;

    Stack stk;

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        stk.AddAtHead(ele);
    }
    stk.Pop();
    // stk.Pop();
    // stk.Pop();

    cout << stk.getMin() << endl;
    // stk.Pop();
    // stk.Pop();
    // stk.Pop();
    // cout << stk.Top() << endl;
    stk.print();
}
