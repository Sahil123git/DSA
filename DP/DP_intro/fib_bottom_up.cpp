#include <iostream> //bottom to up using iteration
using namespace std;
int fib_fnd(int n) // TC: O(n) and SC: O(n)
{                  // becoz used extra arr(dp) so thatswhy SC: O(n)
    if (n <= 1)
    {
        return n;
    }
    int dp[100] = {0};
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int fib_sp_opt(int n) // TC: O(n) and SC: O(1)
{
    if (n <= 1)
    {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b; // here c is saving all val
        a = b;
        b = c;
    }
    return c;
}
int main()
{
    int n;
    cin >> n;

    cout << fib_fnd(n) << " " << fib_sp_opt(n);
}