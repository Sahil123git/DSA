#include <bits/stdc++.h>
using namespace std;
class Stack
{
    vector<int> vc;
    stack<int> stk;
    int mini = INT_MAX;

public:
    void Push(int ele)
    {
        vc.push_back(ele);

        // get_min implementation
        if (ele <= mini)
        {
            stk.push(ele);
            mini = ele;
        }
    }

    void Pop()
    {
        if (vc.empty())
        {
            cout << "UnderFlow" << endl;
        }
        else
        {
            // for get_min implementation
            if (vc[0] == stk.top())
            {
                stk.pop();

                if (stk.empty())
                {
                    mini = INT_MAX;
                }
                else
                {
                    mini = stk.top();
                }
            }
            // ends here

            // vc.erase(vc.begin());
            vc.pop_back();
            // cout << vc[0] << "new first " << endl;
        }
    }

    void Top()
    {
        if (vc.empty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << vc[0];
        }
    }

    void GetMid()
    {
        if (vc.empty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            if (vc.size() % 2 == 0)
            {
                cout << vc[(vc.size() - 1) / 2] << endl;
            }
            else
            {
                cout << vc[(vc.size()) / 2] << endl;
            }
        }
    }

    void getMin()
    {
        cout << mini << endl;
    }
};

int main()
{
    Stack stk;
    stk.Push(3);
    stk.Push(10);

    stk.GetMid();
    // stk.getMin();

    // stk.Pop();
    stk.Push(1);

    stk.Push(9);
    stk.Push(11);
    stk.Push(12);

    stk.Pop();
    // stk.Pop();
    // stk.Pop();
    // stk.Pop();
    // stk.Pop();
    // stk.GetMid();

    // stk.Push(13);
    // stk.Push(14);
    // stk.Push(15);
    stk.GetMid();
}