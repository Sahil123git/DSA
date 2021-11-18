#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = 0, mul = 1;
    while (n > 0)
    {
        int last_b = (n & 1);
        ans = ans + (mul * last_b);
        mul *= 10;
        n = n >> 1;
    }
    cout << ans;
}