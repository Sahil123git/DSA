int minSteps(int N) // Bottom up approach
{                   // GFG for submission
                    // https://practice.geeksforgeeks.org/problems/minimum-steps-to-minimize-n-as-per-given-condition0618/1
    int arr[10001] = {0};
    // arr[1]=0;

    for (int i = 2; i <= N; i++)
    {
        int val1 = INT_MAX, val2 = INT_MAX, val3 = INT_MAX;
        if (i % 3 == 0)
        {
            val1 = arr[i / 3] + 1;
        }
        if (i % 2 == 0)
        {
            val2 = arr[i / 2] + 1;
        }

        val3 = arr[i - 1] + 1;

        arr[i] = min({val1, val2, val3});
    }
    return arr[N];
}
//-------------------------------------------------------------------------------

int min_st(int dp[], int n) // top to bottom approach using recursion and memoization
{
    if (n == 1)
    {
        return 0;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }

    int val1, val2, val3;
    val1 = val2 = val3 = INT_MAX;
    if (n % 3 == 0)
    {
        val1 = min_st(dp, n / 3) + 1;
    }
    if (n % 2 == 0)
    {
        val2 = min_st(dp, n / 2) + 1;
    }
    val3 = min_st(dp, n - 1) + 1;
    dp[n] = min({val1, val3, val2});
    return dp[n];
}
int minSteps(int N)
{
    // Your code goes here
    int dp[10001] = {0};
    return min_st(dp, N);
}