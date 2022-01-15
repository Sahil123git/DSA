int fnd_cn_chng(vector<int> &coins, int n, int amt, vector<vector<int>> &dp_arr) // Unbounded KnapSack Method
{                                                                                // ways to make amt 0 from the gvn coins
    if (amt == 0)                                                                // when amt is 0
    {
        return 1;
    }
    if (amt != 0 && n == 0) // when amt is not 0 but we have chkd all coins
    {
        return 0;
    }
    else if (dp_arr[n][amt] != -1) // already computed case
    {
        return dp_arr[n][amt];
    }
    else if (amt >= coins[n - 1]) // amt can be dec from the ptng coin or can't dec
    {
        return fnd_cn_chng(coins, n, amt - coins[n - 1], dp_arr) + fnd_cn_chng(coins, n - 1, amt, dp_arr);
    }
    else // if amt is smaller than ptng coins
    {
        return fnd_cn_chng(coins, n - 1, amt, dp_arr);
    }
}
int coinChange(vector<int> &coins, int amt)
{
    vector<vector<int>> dp_arr(coins.size() + 1, vector<int>(amt + 1, -1)); // initially all ele of dp_arr initialized with -2
    return fnd_cn_chng(coins, coins.size(), amt, dp_arr);
}
/* i/p: [1,2]
        3

   o/p: 2

   Dry run
   it will fst go to 2 and subtract 2 from 3 =1 or it will not subtract 2
   subtracted will become 1 and again subtract 1 from 1
   and not subtracted will also get subtracted three times from 1
   and result be 0 so in total 2 ways
*/