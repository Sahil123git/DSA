#include <iostream>
#include <stack>
using namespace std;
class queue
{
    stack<int> s1, s2;

public:
    void push(int ele)
    {
        s1.push(ele);
    }
    void pop()
    {
        while (s1.size() != 1)
        {
            int ele;
            ele = s1.top();
            s2.push(ele);
            s1.pop();
        }
        s1.pop();
        while (s2.size() != 0)
        {
            int ele;
            ele = s2.top();
            s1.push(ele);
            s2.pop();
        }
    }
    int front()
    {
        while (s1.size() != 1)
        {
            int ele;
            ele = s1.top();
            s2.push(ele);
            s1.pop();
        }
        int elem = s1.top();
        while (s2.size() != 0)
        {
            int ele;
            ele = s2.top();
            s1.push(ele);
            s2.pop();
        }
        return elem;
    }
    int size()
    {
        int size_ = s1.size();
        return size_;
    }
    bool isEmpty()
    {
        return s1.empty();
    }
};
int main()
{
    queue qu; //this quack is class
    qu.push(10);
    qu.push(20);
    qu.pop();
    qu.pop();
    qu.push(30);
    cout << qu.size() << " " << qu.front() << " " << qu.isEmpty() << endl;
    qu.push(40);
    cout << qu.size() << " " << qu.front() << " " << qu.isEmpty() << endl;
}