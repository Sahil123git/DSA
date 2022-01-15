#include <iostream> //cut the rod of len n in max price
using namespace std;
int max_profit(int n, int price_arr[], int dp_arr[])
{
    if (n <= 0)
    {
        // cout << n << " ";
        return 0;
    }
    if (dp_arr[n] != 0)
    {
        // cout << "i am here" << endl;
        return dp_arr[n];
    }
    int ans = INT8_MIN;
    for (int i = 0; i < n; i++) // it will iterate till n. Had it been the value of prev cut as 8 which could have make this n as 0 then this loop would have not been iterated even for 1 val also.
    {
        int cut = i + 1, cur_ans = INT8_MIN;
        // Incr val of i and inserting in cut becoz tht val index in price_arr is acc to 0 based index so inc by 1

        cur_ans = price_arr[i] + max_profit(n - cut, price_arr, dp_arr); // here we'll dec the val of n
        // cout << cur_ans << " " << arr[i] << endl;

        ans = max(ans, cur_ans);
    }
    return dp_arr[n] = ans;
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
    int dp_arr[n + 1] = {0};
    cout << max_profit(n, arr, dp_arr);
}
/*8 ->len of rod
1 5 8 9 10 17 17 20 ->prices arr
Ans=22 [from 5(ind=1,cut=2)+17(ind=5,cut=6)]*/