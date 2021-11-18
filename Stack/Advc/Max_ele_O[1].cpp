#include <iostream>
#include <stack>
using namespace std;
int max_el;
stack<int> s;
int max_ele()
{
    if (s.size() == 0)
    {
        return -1;
    }
    return max_el;
}
void push(int ele)
{
    if (s.size() == 0)
    {
        s.push(ele);
        max_el = ele;
    }
    else
    {
        if (ele <= max_el) //but when the ele is not greater then we can directly push
        {
            s.push(ele);
        }
        else if (ele > max_el) //here if ele is greater then only change
        {
            s.push((2 * ele) - max_el);
            max_el = ele;
        }
    }
}
int top()
{
    if (s.top() == 0)
    {
        return -1;
    }
    else if (s.top() <= max_el)
    {
        return s.top();
    }
    else if (s.top() > max_el)
    {
        return max_el;
    }
    return 0;
}

void pop()
{
    if (s.size() == 0)
    {
        return;
    }
    else if (s.top() <= max_el) //here only sign changed rest same
    {                           //compared to Min_ele_O[1]
        s.pop();
    }
    else if (s.top() > max_el)
    {
        max_el = (2 * max_el) - s.top();
        s.pop();
    }
}

int main()
{
    push(100);
    push(25);
    push(3);
    pop();
    cout << top() << " top ";
    cout << max_ele() << " max " << endl;
    push(40);
    cout << top() << endl;
    cout << max_ele() << endl;
    return 0;
}
