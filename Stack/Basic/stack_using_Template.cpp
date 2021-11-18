#include <bits/stdc++.h>
using namespace std;
template <typename t>
class Mystack
{
private:
    vector<t> v;

public:
    int top = -1;     //initializing top with -1 so that while assessing it
    void push(t data) //we don't have to dec it.
    {
        v.push_back(data);
        top++;
    }
    t pop()
    {
        if (top == -1)
        {
            cout << endl
                 << "stack is already empty" << endl;
        }
        t data = v.back();
        v.pop_back();
        top--;
        return data;
    }
    t peek()
    {
        return v[top];
    }
    bool empty()
    {
        if (v.empty()) //empty() is a function in vector
        {
            return 1;
        }

        return 0;
    }
};
int main()
{
    Mystack<char> s;
    for (int i = 65; i < 70; i++)
    {
        s.push(i);
        // cout << (char)i << " ";
    }

    cout << s.top << endl;
    while (!s.empty())
    {
        cout << s.peek() << " ";
        s.pop();
    }
    return 0;
}