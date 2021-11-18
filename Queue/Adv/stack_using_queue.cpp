#include <iostream>
#include <queue>
using namespace std;
class stack
{
public:
    queue<int> q1, q2;
    void push(int ele)
    {
        q1.push(ele);
    }
    void pop()
    {
        while (q1.size() != 1)
        {
            int ele = q1.front();
            q2.push(ele);
            q1.pop();
        }
        q1.pop();
        swap(q1, q2);
    }
    int top()
    {
        while (q1.size() != 1)
        {
            int ele = q1.front();
            q2.push(ele);
            q1.pop();
        }
        int ele = q1.front();
        q1.pop();
        q2.push(ele);
        swap(q1, q2);
        return ele;
    }
    int size()
    {
        int size_ = q1.size();
        return size_;
    }
    bool isEmpty()
    {
        return q1.empty();
    }
};
int main()
{
    stack st; //this stack is class
    st.push(10);
    st.push(20);
    // st.push(30);
    cout << st.size() << " " << st.isEmpty() << endl;
    st.push(40);
    st.pop();

    cout << st.top();
}