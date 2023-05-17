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

Node *dummy, *head;
class Stack
{
public:
    Stack()
    {
        dummy = new Node(-1);
        head = dummy;
    }
    void push(int val)
    {
        Node *save = dummy->next;
        dummy->next = new Node(val);
        dummy->next->next = save;
    }

    void pop()
    {
        if (dummy->next != NULL)
        {
            dummy->next = dummy->next->next;
        }
        else
        {
            cout << "No node is present";
        }
    }

    void top()
    {
        if (dummy->next != NULL)
        {
            cout << dummy->next->node << endl;
        }
    }
};
int main()
{
    Stack st;
    st.push(1);
    st.push(2);

    st.pop();
    st.push(3);
    st.top();

    st.push(4);
    st.push(5);

    st.top();
}