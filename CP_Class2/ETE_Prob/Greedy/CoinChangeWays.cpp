
long long countSum(int coins[], int N, int sum, int ind, vector<vector<long long>> &dp)
{
    if (sum == 0)
    {
        return 1;
    }
    if (ind < 0 || sum < 0)
    {
        // cout << "herke";
        return 0;
    }
    if (dp[ind][sum] != -1)
    {
        // cout <<"here"<<endl;
        return dp[ind][sum];
    }
    // if(coins[ind] == 0) {
    //     return ()
    // }
    return dp[ind][sum] = (countSum(coins, N, sum - coins[ind], ind, dp) + countSum(coins, N, sum, ind - 1, dp));
}

long long int count(int coins[], int N, int sum)
{

    vector<vector<long long>> dp(N, vector<long long>(sum + 1, -1));
    return countSum(coins, N, sum, N - 1, dp);
}

// https://practice.geeksforgeeks.org/problems/coin-change2448/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article