#include <iostream>
using namespace std;

int mul_t(int n, int mul)
{
    if (mul == 0)
    {
        return 0;
    }
    if (mul == 1)
    {
        return n;
    }
    return n + mul_t(n, mul - 1);
}

int main()
{
    int n, mul;
    cin >> n >> mul;
    cout << mul_t(n, mul) << endl;
    return 0;
}