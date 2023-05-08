#include <iostream>
#include <vector>

using namespace std;
class Twostack1Arr
{
public:
    int low, end, size;
    int *stk1;
    Twostack1Arr(int sz)
    {
        this->low = 0;
        this->end = sz - 1;
        stk1 = new int[sz];
        size = sz;
    }

    void _pushstk1(int val)
    {
        if (low <= end)
        {
            stk1[low] = val;
            low++;
        }
        else
        {
            cout << "No space to push any ele";
        }
    }
    void _pushstk2(int val)
    {
        if (low <= end)
        {
            stk1[end] = val;
            end--;
        }
        else
        {
            cout << "No space to push any ele";
        }
    }
    void _popStk1()
    {
        if (low > 0)
        {
            stk1[low - 1] = 0;
            low--;
        }
    }
    void _popStk2()
    {
        if (end < (size - 1))
        {
            stk1[end + 1] = 0;
            end++;
        }
    }
    void printA()
    {
        for (int i = 0; i < size; i++)
        {
            cout << stk1[i] << " ";
        }
    }
};
int main()
{
    Twostack1Arr n(5);
    n._pushstk1(1);
    n._pushstk2(2);
    n._pushstk2(3);
    n._pushstk1(4);
    n._pushstk1(6);
    n._pushstk2(6);

    n.printA();
    n._popStk1();
    n._popStk2();
}