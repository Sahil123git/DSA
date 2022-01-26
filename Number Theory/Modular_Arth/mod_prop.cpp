#include <iostream>
#define int long long int
using namespace std;
const int p = 5;

int add_mod(int num1, int num2)
{
    return (num1 + num2) % p;
}

int sub_mod(int num1, int num2)
{
    return ((num1 - num2) % p + p) % p;
}

int mul_mod(int num1, int num2)
{
    return ((num1 % p * num2 % p) % p);
}
int fst_exp(int num, int pwr)
{
    int res = 1;
    while (pwr)
    {
        if (pwr & 1)
        {
            res = (1ll * res * num) % p;
        }
        num = (num * 1ll * num) % p;
        pwr = pwr >> 1;
    }
    return res;
}
int div_mod(int num1, int num2)
{
    return ((num1 % p) * fst_exp(num2, p - 2));
}

int32_t main()
{
    int num1, num2;
    cin >> num1 >> num2;
    cout << add_mod(num1, num2) << endl;
    cout << sub_mod(num1, num2) << endl;
    cout << mul_mod(num1, num2) << endl;
    cout << div_mod(num1, num2) << endl;

    return 0;
}