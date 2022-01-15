#include <iostream>
using namespace std;
int fnd_max(int arr[], int n)
{
    int dp[100] = {0};
    dp[0] = arr[0] > 0 ? arr[0] : 0;
    int max_ans = arr[0]; // don't keep it becoz ele can be in -ve also

    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1] + arr[i]; // if we are getting dp[i] as -ve then don't compute this
        if (dp[i] < 0)              // this is the condition make tht val 0
        {
            dp[i] = 0;
        }
        max_ans = max(max_ans, dp[i]);
    }
    return max_ans;
}

int fnd_max_sp_opt(int arr[], int n) // using Kadane's algo
{
    int max_sum = 0, whole_max_sm = INT8_MIN;
    for (int i = 0; i < n; i++)
    {
        max_sum = max_sum + arr[i];
        if (max_sum < 0)
        {
            max_sum = 0;
        }
        whole_max_sm = max(max_sum, whole_max_sm);
    }
    // cout << arr[i];
    return whole_max_sm;
}
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << fnd_max(arr, n);
    cout << endl
         << fnd_max_sp_opt(arr, n);
    return 0;
}