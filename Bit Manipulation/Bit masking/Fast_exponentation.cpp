#include <iostream>
using namespace std;
int main()
{
    int n, a;
    cin >> n >> a;
    int ans = 1;
    while (a > 0)
    {
        if (a & 1)
        {
            ans = ans * n;
        }
        n = n * n;
        a = a >> 1;
    }
    cout << ans;
    return 0;
}