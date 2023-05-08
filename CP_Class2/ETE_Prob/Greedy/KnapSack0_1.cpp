int fndMaxVal(int cpty, int ind, int wt[], int val[], int n, vector<vector<int>> &dp)
{
    if (ind < 0)
    {
        return 0;
    }

    if (dp[cpty][ind] != -1)
    {
        return dp[cpty][ind];
    }
    if (cpty >= wt[ind])
    {
        return dp[cpty][ind] = max(val[ind] + fndMaxVal(cpty - wt[ind], ind - 1, wt, val, n, dp), fndMaxVal(cpty, ind - 1, wt, val, n, dp));
    }
    else
    {
        return dp[cpty][ind] = fndMaxVal(cpty, ind - 1, wt, val, n, dp);
    }
}

int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here
    vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1));
    return fndMaxVal(W, n - 1, wt, val, n, dp);
}