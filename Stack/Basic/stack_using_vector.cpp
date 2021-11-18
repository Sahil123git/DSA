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
int main()
{
    Mystack s;
    s.push_b(5);
    s.push_b(6);

    cout << s.size() << " size of stack " << endl;
    cout << s.pop_b() << " removing ele" << endl;
    cout << s.peek() << " to checking the pointer" << endl;
    cout << s.pop_b() << " rem ele " << endl;
    s.push_b(7);
    cout << s.pop_b() << " rem ele " << endl;

    cout << s.isEmpty() << " is empty" << endl;
    return 0;
}
