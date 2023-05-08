#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    stack<int> stk, maxi;
    int maxEle = INT_MIN;

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
            if (stk.top() == maxEle)
            {
                maxi.pop();
                if (maxi.empty())
                {
                    maxEle = INT_MAX;
                }
                else
                {
                    maxEle = maxi.top();
                }
            }
            stk.pop();
        }
    }

    void Push(int ele)
    {
        stk.push(ele);
        if (ele >= maxEle)
        {
            maxEle = ele;
            maxi.push(maxEle);
        }
    }

    int getMax()
    {
        return maxEle;
    }
};
int main()
{
    Stack s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    cout << s.getMax() << " max ele" << endl;
    s.Push(0);

    s.Pop();
    s.Pop();
    cout << s.getMax() << " max ele" << endl;
    cout << s.Top() << endl;
    cout << s.Top() << endl;
}