#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    queue<int> qu;
    vector<int> QuArr;

    void Push(int ele)
    {
        qu.push(ele);
        QuArr.push_back(ele);
    }

    void Pop()
    {
        if (qu.empty())
        {
            cout << "Queue is empty" << endl;
        }
        else if (!qu.empty())
        {
            qu.pop();
            QuArr.erase(QuArr.begin());
        }
    }
    void Front()
    {
        if (qu.empty())
        {
            cout << "Queue is empty" << endl;
        }
        else if (!qu.empty())
        {
            cout << QuArr[0] << endl;
        }
    }

    void GetMid()
    {
        if (qu.empty())
        {
            cout << "Queue is empty " << endl;
        }
        else
        {
            int n = QuArr.size();
            cout << "Mid ele is " << QuArr[(n - 1) / 2] << endl;
        }
    }
};
int main()
{
    Queue qu; // FIFO
    qu.Push(1);
    qu.Push(5);
    qu.Push(12);
    qu.Push(3);

    qu.Front();
    qu.Pop();
    qu.Front();

    qu.GetMid();
}