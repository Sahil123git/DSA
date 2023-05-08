#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    stack<int> stk, mini;
    int minEle = INT_MAX;

    int Top()
    {
        if (stk.size() == 0)
        {
            return -1;
        }
        else
        {
            return stk.top();
        }
    }

    void Pop()
    {
        if (stk.empty())
        {
            cout << "Underflow" << endl;
        }
        else
        {
            if (stk.top() == minEle)
            {
                mini.pop();
                if (mini.empty())
                {
                    minEle = INT_MAX;
                }
                else
                {
                    minEle = mini.top();
                }
            }
            stk.pop();
        }
    }

    void Push(int ele)
    {
        stk.push(ele);
        if (ele <= minEle)
        {
            minEle = ele;
            mini.push(minEle);
        }
    }

    int getMin()
    {
        return minEle;
    }
};
int main()
{
    Stack s;
    s.Push(1);
    s.Push(3);
    s.Push(2);
    cout << s.getMin() << " min ele" << endl;
    s.Push(0);
    cout << s.getMin() << " min ele" << endl;

    s.Pop();
    cout << s.Top() << endl;
    s.Pop();
    cout << s.Top() << endl;
}