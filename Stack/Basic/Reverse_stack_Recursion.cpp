#include <bits/stdc++.h>
using namespace std;
class Mystack
{
private:
    vector<int> v;

public:
    int top;

    void push_b(int ele)
    {
        v.push_back(ele);
        top++;
    }
    int pop_b()
    {
        if (top == 0)
        {
            cout << "Stack is full " << endl;
        }
        int data = v.back();
        v.pop_back();
        top--;
        return data;
    }
    int peek()
    {
        return v.back();
    }
    int size()
    {
        return v.size();
    }
    bool isEmpty()
    {
        return v.empty();
    }
};
void insert_bottom(Mystack &s1, int data1)
{
    if (s1.isEmpty())
    {
        s1.push_b(data1);
        return;
    }
    int data2 = s1.pop_b();
    insert_bottom(s1, data1);
    s1.push_b(data2);
    // cout << s1.peek() << " p ";
}
void rev_stack(Mystack &s1)
{
    if (s1.isEmpty())
    {
        return;
    }
    int data = s1.pop_b();
    rev_stack(s1);
    insert_bottom(s1, data);
}
int main()
{
    Mystack s;
    s.push_b(5);
    s.push_b(6);
    s.push_b(7);
    s.push_b(8);
    s.push_b(9);
    s.push_b(10);

    rev_stack(s);
    while (!s.isEmpty())
    {
        cout << s.pop_b() << " ";
    }
    return 0;
}
