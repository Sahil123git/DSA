#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool top_down_sub(int n, int arr[], int sum, vector<vector<int>> &dp_arr) // DP to optimize this code
    {
        if (sum == 0 || (sum == 0 && n == 0)) // base case when sum=0 directly return 1
        {
            // cout << "d"<<sum<<endl;
            return 1;
        }
        else if (n == 0 && sum != 0) // if sum!=0 but n==0 then tht means we are not having ele whch can make our gvn sum
        {                            // this sum=0
            return 0;
        }
        else if (dp_arr[n][sum] != -1) // if we have already computed this
        {
            // cout << "d";
            return dp_arr[n][sum];
        }
        else if (sum >= arr[n - 1]) // if sum is greater then arr[n-1] then chk 2 cases
        {                           // 1st with subtracting with arr[n-1]val and 2nd w/o subtracting with arr[n-1]val
            return dp_arr[n][sum] = (top_down_sub(n - 1, arr, sum - arr[n - 1], dp_arr) || top_down_sub(n - 1, arr, sum, dp_arr));
        }
        else // sum < arr[n-1] if sum is smaller how we can subtract arr[n-1] from sum
        {
            return dp_arr[n][sum] = top_down_sub(n - 1, arr, sum, dp_arr);
        }
    }
    bool sSubsetSum(int n, int arr[], int sum)
    {
        // code here
        vector<vector<int>> dp_arr(n + 1, vector<int>(sum + 1, -1));
        int ans = top_down_sub(n, arr, sum, dp_arr);
        // for (auto it : dp_arr)
        // {
        //     for (auto iit : it)
        //     {
        //         cout << iit << " ";
        //     }
        //     cout << endl;
        // }
        return ans;
    }

    bool isSubsetSum(int n, int arr[], int sum) // Bottom up approach
    {
        vector<vector<int>> dp_arr(n + 1, (vector<int>(sum + 1, 0)));

        for (int i = 0; i <= n; i++) // i:arr.size()
        {
            for (int j = 0; j <= sum; j++) // j:sum(cpty)
            {
                if (i == 0) // base case to initialization
                {           // if arr.size is 0 then tht means all ele are chkd no ele left
                    dp_arr[i][j] = 0;
                }
                if (j == 0) // if sum(cpty) is 0 then we don't even have to chk
                {
                    dp_arr[i][j] = 1;
                    continue;
                }
                if (i != 0 && j >= arr[i - 1]) // other 2 cases and handle i also
                {
                    dp_arr[i][j] = (dp_arr[i - 1][j - arr[i - 1]] || dp_arr[i - 1][j]);
                }
                else if (i != 0 && j < arr[i - 1])
                {
                    dp_arr[i][j] = dp_arr[i - 1][j];
                }
            }
        }

        return dp_arr[n][sum];
    }
};
// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.sSubsetSum(N, arr, sum) << endl;
    }
    return 0;
}
// }