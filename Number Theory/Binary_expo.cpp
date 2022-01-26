#include <iostream>
using namespace std;
int m = 1e+7;
int chk_naive(int num, int pow) // naive mthd  TC:O(pow)
{
    int res = 1;
    for (int i = 0; i < pow; i++) // sinply mul num pow times
    {
        res *= num;
    }
    return res;
}

int chk_pwr(int num, int pow) // Recursive  TC:O(log pow)
{
    if (pow == 0)
        return 1;

    int sv = chk_pwr(num, pow / 2);
    if (pow & 1) // multiply extra num becoz pow is odd
    {
        return (1ll * num * sv * sv) % m;
    }
    else // no need to multiply extra num becoz this is even
    {
        return (1ll * sv * sv) % m;
    }
}

int chk_pwr_iter(int num, int pow) // iterative  TC:O(log pow)
{
    int res = 1;
    while (pow)
    {
        if (pow & 1) // if last bit is set
        {
            res = (1ll * res * num) % m; // if bit is set then storing in res
        }
        num = (num * 1ll * num) % m; // mul num with num
        pow = pow >> 1;              // right shifting pow
    }
    return res;
}

int main()
{
    int num, pow;
    cin >> num >> pow;

    cout << chk_naive(num, pow) << endl;
    cout << chk_pwr(num, pow) << endl;
    cout << chk_pwr_iter(num, pow);
}