#include <iostream>
using namespace std;
int profit(int n, int bag_cpty, int weight[], int prices[])
{
    if (n == 0 || bag_cpty == 0)
    {
        return 0;
    }
    int ans = 0;
    int inc, exp;
    inc = exp = 0;
    if (weight[n - 1] <= bag_cpty)
    {
        inc = prices[n - 1] + profit(n - 1, bag_cpty - weight[n - 1], weight, prices);
    }
    exp = profit(n - 1, bag_cpty, weight, prices);

    ans = max(inc, exp);
    return ans;
}
int main()
{
    int weight[] = {1, 2, 3, 4};
    int prices[] = {40, 20, 30, 100}; //prices of the listed items

    int n = 4;
    int bag_cpty = 6;
    cout << profit(n, bag_cpty, weight, prices);
    return 0;
}