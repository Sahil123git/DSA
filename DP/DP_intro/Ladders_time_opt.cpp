#include <iostream>
using namespace std;
int ladder_bottom_top(int n, int k, int dp[]) // T.C->O(n^2)  SC->O(n)
{
    dp[0] = 1;
    for (int i = 1; i <= k; i++) // this will calculate till k
    {
        int ways = 0;                // this mthd is not effective when (k==n)
        for (int j = 1; j <= k; j++) // becoz then only this will work and TC will be O(n^2)
        {
            if (i - j >= 0)
            {
                ways += dp[i - j];
            }
        }
        dp[i] = ways;
    }

    for (int i = k + 1; i <= n; i++) // Now we will use tht counted in this
    {
        dp[i] = dp[i - 1] - dp[i - 1 - k] + dp[i - 1];
    } // for dp[i] we'll subtract dp[i-k-1] from dp[i-1] and then add dp[i-1] as value
    // what we are doing :We are subtracting(dp[i-1-k] 1st val from dp[i-1]) and adding the prev val(dp[i-1]) to the curr dp[i] It is like sliding window
    return dp[n];
}
int main()
{
    int n, k;
    cin >> n >> k;
    int dp[n + 1] = {0};
    cout << ladder_bottom_top(n, k, dp) << endl;

    cout << "To see how it is happening" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] << " ";
    }
}