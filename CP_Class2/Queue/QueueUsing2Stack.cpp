#include <iostream>
#include <stack>
using namespace std;

class Queue
{
public:
    stack<int> pushStk, popStack;
    void pPush(int ele)
    {
        pushStk.push(ele);
    }

    int pPop()
    {
        if (popStack.empty() && pushStk.empty())
        {
            cout << "No ele is available Stack is empty" << endl;
            return -1;
        }

        if (popStack.empty()) // first popStack should be empty and then push in popStack and pop from pushStack
        {
            while (!pushStk.empty())
            {
                popStack.push(pushStk.top());
                pushStk.pop();
            }
        }
        int top = popStack.top();
        popStack.pop();
        return top;
    }
};
int main()
{
    stack<int> stk;
    Queue qu;

    qu.pPush(4);
    qu.pPush(5);
    qu.pPush(8);

    cout << qu.pPop() << endl;
    cout << qu.pPop() << endl;
    cout << qu.pPop() << endl;
    cout << qu.pPop() << endl;
}