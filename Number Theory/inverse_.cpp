#include <iostream>
#include <vector>
using namespace std;
vector<int> euclid_algo(int num1, int num2)
{
    if (num2 == 0)
    {
        return {1, 0, num1};
    }
    vector<int> result = euclid_algo(num2, num1 % num2);

    int smallx = result[0];
    int smally = result[1];
    int gcd = result[2];

    int x = smally;
    int y = smallx - (num1 / num2) * smally;

    return {x, y, gcd};
}
int inv_num(int num, int mod) // inv usng Euclid algo(opt method)
{
    vector<int> result = euclid_algo(num, mod);
    int x = result[0], gcd = result[2]; // we need inv of num,Inv we can fnd in result[0]
    // cout << x << " " << gcd << endl;
    if (gcd != 1) // if gcd is 1 then only gcd will exist
    {
        cout << "inv not exist" << endl;
        return 0;
    }
    int inv = (x % mod + mod) % mod;
    return inv;
}
int inv_clc_naive(int num, int mod) // naive method
{
    num = num % mod; // if num val is greater than mod
    // cout << num << endl;
    for (int i = 1; i <= mod - 1; i++)
    {
        // cout << (num * i) % mod << " " << num << " " << i << endl;
        if ((num * i) % mod == 1) // inv is when rem is 0
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int num, mod;
    cin >> num >> mod;
    int inv_naive = inv_clc_naive(num, mod);
    int inv_opt = inv_num(num, mod);
    cout << "inv usng naive " << inv_naive << " \ninv usng opt " << inv_opt;
}