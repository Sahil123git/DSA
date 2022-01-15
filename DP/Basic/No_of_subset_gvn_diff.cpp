#include <iostream>
#include <vector>
using namespace std;
int fnd_sub(int n, int *arr, int sub_fnd, vector<vector<int>> &dp_arr)
{
    if (sub_fnd == 0)
    {
        return 1;
    }
    if (sub_fnd != 0 && n == 0)
    {
        return 0;
    }
    if (dp_arr[n][sub_fnd] != -1)
    {
        return dp_arr[n][sub_fnd];
    }
    if (sub_fnd >= arr[n - 1])
    {
        return dp_arr[n][sub_fnd] = (fnd_sub(n - 1, arr, sub_fnd - arr[n - 1], dp_arr) + fnd_sub(n - 1, arr, sub_fnd, dp_arr));
    }
    else
    {
        return dp_arr[n][sub_fnd] = fnd_sub(n - 1, arr, sub_fnd, dp_arr);
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    int arr[n], sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int dif, sub_fnd;
    cin >> dif;
    sub_fnd = (dif + sum) / 2; // sub_fnd is 1st half of subset. (Sub1-Sub2=dif)

    vector<vector<int>> dp_arr(n + 1, vector<int>(sub_fnd + 1, -1));
    cout << fnd_sub(n, arr, sub_fnd, dp_arr);
}
/*4
1 3 2 3
5
 output-> 1
 tht is (1+3+3)=7 1st subset - (2) 2nd subset = 5 (ans)
 */