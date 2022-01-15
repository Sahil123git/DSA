#include <bits/stdc++.h> //Bottom UP approach
using namespace std;     // https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/

// } Driver Code Ends
class Solution
{

public:
    bool bottom_up_subset(int n, int arr[], int sum, vector<vector<int>> &dp_arr)
    {
        for (int i = 0; i < dp_arr.size(); i++)
        {
            for (int j = 0; j < dp_arr[i].size(); j++)
            {
                if (j == 0)
                {
                    dp_arr[i][j] = 1;
                    continue;
                }
                if (i == 0 && j != 0)
                {
                    dp_arr[i][j] = 0;
                    continue;
                }
                if (arr[i - 1] <= j)
                {
                    dp_arr[i][j] = (dp_arr[i - 1][j - arr[i - 1]] || dp_arr[i - 1][j]);
                }
                else
                {
                    dp_arr[i][j] = dp_arr[i - 1][j];
                }
            }
        }
        return dp_arr[n][sum];
    }

    int minDifference(int arr[], int n)
    {
        // Your code goes here
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        vector<vector<int>> dp_arr(n + 1, vector<int>(sum + 1, -1));
        bool ans = bottom_up_subset(n, arr, sum, dp_arr);
        vector<int> set_ele; // from dp_arr we'll get to know how many ele we can make from the
        // gvn arr.dp_arr last row will be having all data.

        for (auto it : dp_arr) // Run this, all ele will be marked as 1 in last row which we can make
        {                      // from the gcn arr making
            for (auto iit : it)
            {
                cout << iit << " ";
            }
            cout << endl;
        }
        cout << sum << endl;
        for (int i = 0; i <= sum / 2; i++)               // only chk till half of sum other wise ans can become -ve
        {                                                // We will pick those index which we can make using arr but should be smaller than or equal to sum/2
            if (dp_arr[n][i] != -1 && dp_arr[n][i] != 0) // becoz if min gap is present then
            {                                            // tht will be present before half of sum
                set_ele.push_back(i);                    // this set_ele is SORTED arr
            }
        }
        // for(auto it:set_ele)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        int min_sub = INT_MAX;
        // for (int i = 0; i < set_ele.size(); i++)
        // {
        //     min_sub = min(min_sub, sum - 2 * set_ele[i]); // Formula (Total_sum-2*arr[n-1])
        //     // cout<<min_sub<<" "<<set_ele[i]<<endl;//It will chk all
        // }
        min_sub = sum - 2 * set_ele[set_ele.size() - 1]; // using this also we can do becoz maxi num will be at last and if we subtract with tht we'll get minimum num
        return min_sub;
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
} // } Driver Code Ends
  /*1
  4
  1 6 2 1
  
  2*/