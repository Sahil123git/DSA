#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
stack<int> ss;
void push(int ele)
{
    s.push(ele);
    if (ss.size() == 0 || ss.top() >= ele)
    {
        ss.push(ele);
    }
}
int pop()
{
    if (s.size() == 0)
    {
        return -1;
    }
    int ans = s.top();
    s.pop();

    if (ans == ss.top())
    {
        ss.pop();
    }
    return ans;
}
int get_min()
{
    if (ss.size() == 0)
    {
        return -1;
    }
    return ss.top();
}

int main()
{
    push(10);
    cout << get_min() << " smallest" << endl;
    push(7);
    push(4);
    push(8);
    pop();
    cout << get_min() << " smallest" << endl;
    push(7);
    push(3);
    cout << get_min() << " smallest" << endl;
}