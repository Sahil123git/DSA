#include <iostream>
using namespace std;
#define maxx(a, b) (a > b ? a : b)
#define ct(num) cout << #num
#define cn_1(num1) cin >> num1 
#define cn_2(num1, num2) cin >> num1 >> num2 
#define cn_3(num1, num2, num3) cin >> num1 >> num2 >> num3

bool pythogorus(int a, int b, int c)
{
    int hst, hst_all, hypt;
    int base, perp;
    hst = maxx(a, b);
    hst_all = maxx(hst, c);
    if (hst_all == a)
    {
        hypt = a;
        base = b;
        perp = c;
    }
    if (hst_all == b)
    {
        hypt = b;
        base = a;
        perp = c;
    }
    if (hst_all == c)
    {
        hypt = c;
        base = b;
        perp = a;
    }
    if ((hypt * hypt) == (base * base) + (perp * perp))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int a, b, c;
    cn_3(a, b, c);
    if (pythogorus(a, b, c))
    {
        ct(Pythogorus);
    }
    else
    {
        ct(not Pythogorus);
    }

    return 0;
}
