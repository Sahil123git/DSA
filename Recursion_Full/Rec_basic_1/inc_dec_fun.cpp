#include <iostream>
using namespace std;
void dec(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    dec(n - 1); // top to bottom approach
}
void inc(int n)
{
    if (n == 0)
    {
        return;
    }
    inc(n - 1); // bottom to top apprach
    cout << n << " ";
}
int main()
{
    int n;
    cin >> n;
    dec(n);
    cout << endl;
    inc(n);
}