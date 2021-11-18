#include <bits/stdc++.h>
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
class Mystack
{
private:
    int size = 0;
    Node *head = NULL;

public:
    void push_b(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp; //this will not change the next of temp that will still point head
        // cout << head->next << " T ";
        size++;
    }

    int pop_b()
    {
        Node *temp = head;
        int ele = temp->data;
        head = head->next;
        delete (temp);
        size--;
        return ele;
    }
    int peek()
    {
        if (head == NULL)
        {
            cout << "there is no ele in the stack " << endl;
            return 0;
        }
        return head->data;
    }
    int size_()
    {
        return size;
    }
    bool is_em()
    {
        return head == NULL;
    }
};
int main()
{
    Mystack st;
    st.push_b(1);
    st.push_b(2);
    cout << st.peek() << " peek" << endl;
    st.push_b(3);
    st.push_b(4);
    cout << st.peek() << " peek" << endl;

    cout << st.pop_b() << endl;
    cout << st.pop_b() << endl;
    cout << st.size_() << " size" << endl;
    cout << st.pop_b() << endl;
    cout << st.pop_b() << endl;

    cout << st.is_em() << " empty";
}