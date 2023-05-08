#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        val = data;
        next = NULL;
    }
};
class Stack
{
public:
    int minEle = INT_MAX;
    void _push(int val, Node *dummy) // here we r inserting at head
    {
        if (val <= minEle)
        {
            // cout << "here" << endl;
            Node *nxt = dummy->next;
            dummy->next = new Node(minEle);
            dummy->next->next = nxt;
            minEle = val;
        }
        Node *nxt = dummy->next;
        dummy->next = new Node(val);
        dummy->next->next = nxt;
    }

    void _pop(Node *dummy) // poping ele at head
    {
        if (dummy->next == NULL)
        {
            cout << "No new node is there to pop " << endl;
            return;
        }
        if (dummy->next->val == minEle)
        {
            minEle = dummy->next->next->val;
            dummy->next = dummy->next->next->next;
            return;
        }
        dummy->next = dummy->next->next;
    }
    int getMin()
    {
        if (minEle == -1)
        {
            cout << "no min ele is there" << endl;
            return -1;
        }
        return minEle;
    }
    void print_(Node *dummy)
    {
        Node *nxt = dummy->next;

        while (nxt != NULL)
        {
            cout << nxt->val << " ";
            nxt = nxt->next;
        }
    }
};

int main()
{
    Node *dummy = new Node(-1);
    Stack stk;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        stk._push(ele, dummy);
    }
    stk.print_(dummy);
    cout << endl;
    cout << stk.getMin() << endl;
}