#include <iostream>
using namespace std;

#define maxx(a, b) (a > b ? a : b)
#define Fo1(num) for (int i = 0; i < num - 2; i++)
#define ct(num) cout << #num
#define ct_v1(num) cout << num
#define cn_1(num1) cin >> num1
#define ev_od(num1) (num1 % 2 == 0 ? 1 : 0)
#define cn_2(num1, num2) cin >> num1 >> num2
#define cn_3(num1, num2, num3) cin >> num1 >> num2 >> num3

void dec_to_bin(int);
int main()
{
    int num;
    cn_1(num);
    // num = 90;
    dec_to_bin(num);
}

void dec_to_bin(int num)
{
    int rem, rev = 0, arr[8], count = 0, i;
    for (i = 0; num != 0; i++)
    {
        arr[i] = num % 2;
        num = num / 2;
    }
    for ( i = i - 1; i >= 0; i--)
    {
        cout << arr[i];
    }
}
