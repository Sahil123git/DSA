#include <iostream>
#include <stack>
#include <climits>

using namespace std;
class Stack
{
    int Min;
    stack<int> stk;

public:
    Stack()
    {
        Min = INT_MAX;
    }
    void _push(int ele) // if u are insrtng (min ele) then first push prev min ele in stack and then insert this new min ele otherwise only new ele is sufficient
    {
        if (ele <= Min)
        {
            stk.push(Min);
            Min = ele; // push prev min ele in stack and update Min with new smaller ele
        }
        stk.push(ele); // this is where we are inserting new ele in stack
    }

    void _pop() // if top ele matches with Min ele then first pop top ele and then save next top ele in Min ele and then pop this also
    {
        if (stk.empty())
        {
            cout << "Stack is empty " << endl;
            return;
        }
        else if (stk.top() == Min)
        {
            stk.pop();
            Min = stk.top();
        }
        stk.pop();
    }
    int getMin()
    {
        return Min;
    }
};

int main()
{
    Stack stk;
    stk._push(4);
    stk._push(1);
    stk._push(3);
    stk._push(1);
    stk._pop();
    cout << "Cur min ele is: " << stk.getMin() << endl;
    stk._push(-1);
    stk._push(2);
    stk._pop();
    cout << "Cur min ele is: " << stk.getMin() << endl;
}