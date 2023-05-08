#include <bits/stdc++.h>
using namespace std;

class LinkedLst
{
public:
    int data;
    LinkedLst *next;

    LinkedLst(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class Queue
{
    LinkedLst *dummy = new LinkedLst(-1), *move = dummy;

public:
    void Push(int ele)
    {
        move->next = new LinkedLst(ele);
        move = move->next;
    }

    void Pop()
    {
        if (dummy->next == NULL)
        {
            cout << "UnderFlow" << endl;
        }
        else
        {
            if (dummy->next == move)
            {
                move = dummy;
            }
            dummy->next = dummy->next->next;
        }
    }

    int Front()
    {
        if (dummy->next == NULL)
        {
            cout << "No node is present" << endl;
            return -1;
        }
        else
        {
            return dummy->next->data;
        }
    }
};

int main()
{
    Queue qu;
    qu.Push(1);
    qu.Push(2);
    qu.Push(3);

    qu.Pop();
    qu.Pop();
    qu.Pop();

    qu.Push(9);
    qu.Push(7);
    qu.Pop();

    cout << qu.Front();
}