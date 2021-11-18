#include <iostream> //this is naive approach so we are using 2 stacks
#include <stack>
using namespace std;
stack<int> s;
stack<int> ss;
void push(int ele)
{
    s.push(ele);
    if (ss.size() == 0 || ss.top() <= ele) //this (<=) is very important as it
    {                                      //otherwise pop will remove ele and if that poped out ele is max again it
        ss.push(ele);                      //will not print that ele
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
int get_max()
{
    if (ss.size() == 0)
    {
        return -1;
    }
    return ss.top();
}

int main()
{
    push(1);
    cout << get_max() << " Largest" << endl;
    push(7);
    push(7);
    pop();
    push(4);
    push(18);
    pop();
    cout << get_max() << " Largest" << endl;
    push(11);
    push(3);
    cout << get_max() << " Largest" << endl;
}