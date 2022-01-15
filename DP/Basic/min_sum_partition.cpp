#include <cstdlib>  //min sum partition Top down DP
#include <iostream> //https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/
#include <vector>
using namespace std;
int min_sub(int arr[], int n, int min_ans, int sub2, vector<vector<int>> &dp_arr)
{
    if (n == 0) // base case
    {
        // cout << "n " << min_ans << " " << n - 1 << endl;
        return min_ans;
    }
    if (dp_arr[n][min_ans] != -1) // n and min_ans is chngng so making dp_arr of these var
    {
        // cout << "d"
        //      << " " << min_ans << " " << n - 1 << " " << dp_arr[n][min_ans] << endl;
        return dp_arr[n][min_ans];
    }
    // cout << "f"
    //      << " " << min_ans << " " << n - 1 << endl;

    int chk1 = min_sub(arr, n - 1, abs(sub2 - 2 * arr[n - 1]), sub2 - 2 * arr[n - 1], dp_arr); // this is the case when we are selecting arr[n-1]ele adding this ele to other part of partition and subtracting both partitions
    int chk2 = min_sub(arr, n - 1, min_ans, sub2, dp_arr);                                     // this is the case when we are not selecting this cur ele and directly returning same
    return dp_arr[n][min_ans] = min(chk1, chk2);
}

int minDifference(int arr[], int n)
{
    // Your code goes here
    int sum_diff = 0;
    for (int i = 0; i < n; i++)
    {
        sum_diff += arr[i];
    }
    vector<vector<int>> dp_arr(n + 1, vector<int>(sum_diff + 1, -1));
    return min_sub(arr, n, sum_diff, sum_diff, dp_arr);
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
    cout << minDifference(arr, n);
}
/*10
1 6 9 8 2 5 10 3 5 2
output -> 1

3
2 6 2
output -> 2
*/