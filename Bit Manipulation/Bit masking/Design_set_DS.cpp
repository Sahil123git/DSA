#include <iostream>
using namespace std;
void add(long long &num, int ele)
{
    num = (num | (1 << (ele)));
}
void remove(long long &num, int ele)
{
    num = (num & ~(1 << (ele)));
}
void print(long long &num)
{
    for (int i = 0; i < 60; i++)
    {
        if (num & 1)
        {
            cout << i << " ";
        }
        num = num >> 1;
    }
}
int main()
{
    long long num = 0;
    add(num, 2);
    add(num, 2);
    add(num, 3);
    remove(num, 2);
    add(num, 3);
    print(num);
    return 0;
}