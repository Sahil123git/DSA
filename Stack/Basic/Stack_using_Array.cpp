#include <iostream>
using namespace std;
class Mystack
{
private:
    int *arr;

public:
    int cap;
    int top;
    Mystack(int cap) //for declaring the arr for stack
    {
        this->cap = cap;
        arr = new int[cap];
        top = -1;
    }
    void push_b(int ele) //to pushing the ele into the arr
    {
        if (top == cap - 1)
        {
            cout << "stack is full";
            return;
        }
        top++;
        arr[top] = ele;
    }
    int pop_back() //to removing the ele from last of stack
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        int res = top;
        top--;
        // cout << "TOP " << top << endl;
        return arr[res];
    }
    int peek() //to checking the where the pointer is
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        return arr[top];
    }

    int size() //to checking the size of the stack
    {
        return (top + 1);
    }
    bool isEmpty() //to checking whether the stack is empty or not
    {
        return (top == -1);
    }
};
int main()
{
    Mystack st(5);
    st.push_b(5);
    cout << st.peek() << " peek " << endl;
    st.push_b(6);
    cout << st.pop_back() << " popback" << endl;
    cout << st.size() << " Size " << endl;
    st.push_b(7);
    cout << st.peek() << " peek" << endl;
    cout << st.pop_back() << " pop_back" << endl;
    cout << st.pop_back() << " pop_back" << endl;
    cout << st.size() << " Size " << endl;
    cout << st.isEmpty() << " checking";
    return 0;
}