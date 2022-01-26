#include <iostream>
using namespace std;
long long fnd_fst_mul(long long num1, long long num2, long long m)
{
    long long res = 0;
    while (num2)
    {
        if (num2 & 1)
        {
            res = (res + num1) % m;
        }
        num1 = (num1 + num1) % m; //(or num2*2)
        num2 >>= 1;
    }
    return res;
}
int main()
{
    long long num1, num2;
    cin >> num1 >> num2;

    cout << fnd_fst_mul(num1, num2, 1e9 + 7);
}