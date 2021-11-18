#include <iostream>
#include <stack>
using namespace std;
int min_el;
stack<int> s;
int min_ele()
{
    if (s.size() == 0)
    {
        return -1;
    }
    return min_el;
}
void push(int ele)
{
    if (s.size() == 0)
    {
        s.push(ele);
        min_el = ele;
    }
    else
    {
        if (ele >= min_el)
        {
            // cout << ele << " ele" << endl;
            s.push(ele);
        }
        else if (ele < min_el)
        {
            s.push((2 * ele) - min_el);
            // cout << min_el << " " << ele << " ";
            min_el = ele;
            // cout << "changed " << min_el << endl;
        }
    }
}
int top()
{
    if (s.top() == 0)
    {
        return -1;
    }
    else if (s.top() >= min_el)
    {
        return s.top();
    }
    else if (s.top() < min_el)
    {
        return min_el;
    }
    return 0;
}

void pop()
{
    // cout << s.top() << " T ";
    // cout << top() << endl;
    if (s.size() == 0)
    {
        return;
    }
    else if (s.top() >= min_el)
    {
        s.pop();
    }
    else if (s.top() < min_el)
    {
        // cout << s.top() << " T ";
        min_el = (2 * min_el) - s.top();
        // cout << min_el << " " << s.top() << endl;
        s.pop();
    }
}

int main()
{
    push(100000);
    push(1);
    push(2);
    push(3);
    pop();
    cout << min_ele() << " min " << endl;
    push(4);
    cout << top() << endl;
    cout << min_ele() << endl;
    return 0;
}
