#include <iostream>                         //https://leetcode.com/problems/climbing-stairs/
using namespace std;                        // num of ways to reach nth stair
int ladder_top_down(int n, int k, int dp[]) // TC-O(N.k)  SC-O(N)
{
    if (n == 0)
    {
        return 1;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }
    int ways_cnt = 0;
    for (int i = 1; i <= k; i++) // through this loop we are chkng all pos from 1 to k
    {
        if (n - i >= 0)
        {
            ways_cnt += ladder_top_down(n - i, k, dp); // dec n by i and sndng as argument to another func
        }
    }
    return dp[n] = ways_cnt; // memoizing ans
}
int ladder_bottom_top(int n, int k, int dp[])
{
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int ways = 0;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                ways += dp[i - j];
            }
        }
        dp[i] = ways;
    }
    return dp[n];
}
int main()
{
    int n, k;
    cin >> n >> k;
    int dp[n + 1] = {0}; // creating dp arr for n+1 so tht save data for n
    cout << ladder_top_down(n, k, dp) << endl;
    int n_dp[n + 1] = {0};
    cout << ladder_bottom_top(n, k, n_dp) << endl;

    cout << "To see how it is happening" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << n_dp[i] << " ";
    }
}
/*for n=4 and k=3
7
To see how it is happening
1 2 4 7*/
