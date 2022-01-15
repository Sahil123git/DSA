#include <iostream> //Ques is to sell all wine bottles but with max total profit every year bottle prices inc with their year number like for 2nd year every bottle price will be double of their price and for 3rd year every bottle price will be 3x for 4th 4x like wise for all years
// we can only select 1 bottle tht too from one side either from starting or from ending
using namespace std;
int dp[10][10];
int wines(int arr[], int bg, int en, int n)
{
    if (bg > en) // this is the base when beg is greater than end
    {
        return 0;
    }
    else if (dp[bg][en] != 0) // there will be overlapping cases so use dp.Can do dryrun to chk for overlapping cases
    {
        return dp[bg][en];
    }
    int year = n - (en - bg); // this will count year num
    int prt1 = arr[bg] * year + wines(arr, bg + 1, en, n);
    int prt2 = arr[en] * year + wines(arr, bg, en - 1, n);
    return dp[bg][en] = max(prt1, prt2); // saving the result in dp 2d arr
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
    cout << wines(arr, 0, n - 1, n);
}