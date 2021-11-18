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
void transfer(Mystack &s1, Mystack &s2, int n) //s1 to s2
{
    for (int i = 0; i < n; i++)
    {
        s2.push_b(s1.peek());
        s1.pop_b();
    }
    cout << endl;
}
void reverse_stack(Mystack &s1)
{
    Mystack s2;
    int n = s1.size();
    for (int i = 0; i < n; i++)
    {
        int x = s1.pop_b();
        transfer(s1, s2, n - i - 1);
        s1.push_b(x);
        transfer(s2, s1, n - i - 1);
    }
}
int main()
{
    Mystack s;
    s.push_b(5);
    s.push_b(6);
    s.push_b(7);
    s.push_b(8);
    s.push_b(9);

    reverse_stack(s);
    cout << "After Reversing the data" << endl;

    while (!s.isEmpty())
    {
        cout << s.pop_b() << " ";
    }
    return 0;
}
