#include <iostream>
#include <list>
using namespace std;
class Queue
{
    int cs;
    list<int> l;

public:
    Queue()
    {
        cs = 0;
    }
    bool isEmpty()
    {
        return cs == 0;
    }
    void push(int ele)
    {
        l.push_back(ele);
        cs++;
    }
    void pop()
    {
        if (isEmpty())
        {
            return;
        }
        l.pop_front();
        cs--;
    }
    int front_()
    {
        return l.front();
    }
    int back_()
    {
        return l.back();
    }
};
int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.pop();
    cout << q.front_() << " " << q.back_() << endl;
}