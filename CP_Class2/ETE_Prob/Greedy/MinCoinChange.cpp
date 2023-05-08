#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fndCoin(vector<int> &coins, int amt, int ind, int cnt, vector<vector<int>> &dp)
{ // Optimizing using Dp
    if (amt == 0)
    {
        cout << ind << endl;
        return dp[ind][amt] = cnt;
    }

    if (ind < 0 || amt < 0)
    {
        return -1;
    }
    if (dp[ind][amt] != -2)
    {
        return dp[ind][amt];
    }

    int val1 = fndCoin(coins, amt - coins[ind], ind, cnt + 1, dp);
    int val2 = fndCoin(coins, amt, ind - 1, cnt, dp);

    if (val1 == val2 && val2 == -1)
    {
        return dp[ind][amt] = -1;
    }
    else if (val1 != -1 && val2 != -1)
    {
        return dp[ind][amt] = min(val1, val2);
    }
    else if (val1 != -1)
    {
        return dp[ind][amt] = val1;
    }
    else
    {
        return dp[ind][amt] = val2;
    }
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -2));

    int val = fndCoin(coins, amount, coins.size() - 1, 0, dp);
    // for (auto it : dp)
    // {
    //     for (auto iti : it)
    //     {
    //         cout << iti << " ";
    //     }
    //     cout << endl;
    // }
    return dp[n - 1][amount];
    // return val;
}

int main()
{
    int n;
    cin >> n;

    int amt;
    cin >> amt;

    vector<int> vc(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
    }
    cout << coinChange(vc, amt);
}