#include <iostream>
#include <cmath>
using namespace std;

#define maxx(a, b) (a > b ? a : b)
#define Fo1(num) for (int i = 0; i < num - 2; i++)
#define ct(num) cout << #num
#define ct_vl(num) cout << num
#define cn_1(num1) cin >> num1
#define ev_od(num1) (num1 % 2 == 0 ? 1 : 0)
#define cn_2(num1, num2) cin >> num1 >> num2
#define cn_3(num1, num2, num3) cin >> num1 >> num2 >> num3

int bin_to_dec(int);
int main()
{
    int n, opt;
    cn_1(n);
    opt = bin_to_dec(n);
    ct_vl(opt);
}
int bin_to_dec(int num)
{
    int rev = 0, rem, sum = 0;
    for (int i = 0; num > 0; i++)
    {
        rem = num % 10;
        num = num / 10;
        // rev = (rev * 10) + rem;
        sum += (rem * pow(2, i));
    }
    return sum;
}
