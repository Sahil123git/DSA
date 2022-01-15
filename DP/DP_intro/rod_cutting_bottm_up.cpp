#include <iostream>
using namespace std;
int max_profit(int n, int price_arr[], int dp_arr[])
{
    dp_arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int cur_max_ans = INT8_MIN;
        for (int j = 0; j < i; j++)
        {
            int cut = j + 1; //(price_arr[j] + dp_arr[i - cut]) Bottom up case
            cur_max_ans = max(cur_max_ans, (price_arr[j] + dp_arr[i - cut]));
        }
        dp_arr[i] = cur_max_ans;
    }
    return dp_arr[n];
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