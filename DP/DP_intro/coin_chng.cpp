// **Bottom to up **class Solution
{
public:
    int coinChange(vector<int> &coins, int amt)
    {
        vector<int> dp_arr(amt + 1, -1); // by default dp arr values are initialized with -1
        dp_arr[0] = 0;                   // only for 0 index is 0
        for (int i = 1; i <= amt; i++)   // chk for 1 till amt
        {
            int min_c = INT_MAX, chkd = 0;
            // cout<<i<<" ";
            for (int j = 0; j < coins.size(); j++) // for i amt chkng all coins j
            {
                if (i >= coins[j] && dp_arr[i - coins[j]] != -1)
                {
                    min_c = min(min_c, dp_arr[i - coins[j]] + 1);
                    chkd = 1;
                }
            }

            chkd == 1 ? dp_arr[i] = min_c : chkd; // if u were not able to find any
            // route then u will let -1 inside that coin location
        }
        // for(auto it:dp_arr)
        // {
        //     cout<<it<<" ";
        // }
        return dp_arr[amt];
    }
};

// **Top to down **class Solution
{
public:
    int coin_chng(vector<int> &coin, int amt, vector<int> &dp)
    {
        if (amt == 0)
        {
            return 0;
        }
        if (dp[amt] == -1) // if we cannot make value then return -1
        {
            return -1;
        }
        if (dp[amt] != 0) // if we have already computed this
        {
            return dp[amt];
        }
        int ans = INT_MAX, chkd = 0;
        for (int i = 0; i < coin.size(); i++)
        {
            if (amt >= coin[i])
            {
                int prev_ans = coin_chng(coin, amt - coin[i], dp); // rec call to coin_chng fun with new amt
                if (prev_ans != -1)                                // if we recieved -1 from amt-coin[i] then this will also be -1
                {
                    ans = min(ans, prev_ans + 1);
                    chkd = 1;
                }
            }
        }
        if (chkd == 1)
        {
            return dp[amt] = ans;
        }
        return dp[amt] = -1;
    }

    int coinChange(vector<int> &coin, int amt)
    {
        vector<int> dp(amt + 1, 0); // by default all values are 0
        coin_chng(coin, amt, dp);
        return dp[amt];
    }
};
// ****
// **DRY RUN**
// Like for amt=11,coins{1,5}
// for this 1stly till 4 all will be having 1 using 1coin,
// 2 using 2 one coins, 3 using 3 one coins, 4 using 4 one coins
// 5 using one 5 coin,6 using 1 five coin and 1 one coin

// like wise for 11 it will go 1st (**11 minus 5 coin** tht is 6) 
// for 6 we are having 1 five coin and 1 one coin
// so for **11 ->(1one coin,2 five coin)**