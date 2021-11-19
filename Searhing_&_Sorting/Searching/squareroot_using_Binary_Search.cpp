#include <iostream>
using namespace std;
float square_root(int n, int p)
{
    int start = 0, end = n;
    float ans = -1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid <= n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    float inc = 0.1; //if divided by 10 will become 0.01
    for (int times = 0; times < p; times++)
    {
        while (ans * ans <= n)
        {
            ans = ans + inc;
        }
        ans -= inc;
        inc = inc / 10;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << square_root(n, 3);
    return 0;
}