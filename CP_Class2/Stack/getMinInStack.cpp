#include <iostream> //TC: O(1)
#include <stack>    //SC: O(n) but avg case is O(1)

using namespace std;
class Stack
{
    stack<pair<int, int>> stk;

public:
    void _pop()
    {
        if (stk.empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        else
        {
            stk.pop();
        }
    }

    void _push(int ele)
    {
        if (stk.empty())
        {
            stk.push({ele, ele});
        }
        else
        {
            stk.push({ele, min(ele, stk.top().second)});
        }
    }

    int getMin()
    {
        return stk.top().second;
    }

    int _top()
    {
        return stk.top().first;
    }
};
int main()
{
    Stack stk;
    stk._push(2);
    stk._push(5);
    stk._push(1);
    cout << "Cur min ele " << stk.getMin() << endl;
    stk._pop();
    cout << "Top ele is " << stk._top() << endl;
    cout << "Cur min ele " << stk.getMin() << endl;
}