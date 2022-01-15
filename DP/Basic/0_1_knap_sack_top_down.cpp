#include <iostream> //https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1# and YT Aditya vrma
#include <vector>
using namespace std;

int knapSk(int W, int wt[], int val[], int n, vector<vector<int>> &dp_arr)
{
    // Your code here
    if (W == 0 || n == 0) // base case when, either cpty of knapsack left 0 or checked all weights
    {
        return 0;
    }
    if (dp_arr[W][n] != -1)
    {
        cout << W << " r " << n << endl;
        return dp_arr[W][n];
    }
    if (wt[n - 1] <= W) // if wgt of n-1 is less than knapsack cpty then in 1st case take that wgt and in 2nd case chk val when we leave this wgt.Max of both cases will be taken.
    {
        return dp_arr[W][n] = max(val[n - 1] + knapSk(W - wt[n - 1], wt, val, n - 1, dp_arr), knapSk(W, wt, val, n - 1, dp_arr));
    }
    else if (wt[n - 1] > W) // if wgt of n-1 is more than knapsack cpty
    {
        return dp_arr[W][n] = knapSk(W, wt, val, n - 1, dp_arr);
    }
    return 1;
}
int knapSack(int w, int wt[], int val[], int n)
{
    vector<vector<int>> dp_arr(w + 1, vector<int>(n + 1, -1)); // W+1 becoz it will start from 0 so by inc only it will be having W val
    return knapSk(w, wt, val, n, dp_arr);
}

// In dp_arr we will get our ans at dp[w][n]
int main()
{
    int n, cpty;
    cin >> n >> cpty;

    int values[n], weight[n];
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    cout << knapSack(cpty, weight, values, n);
}