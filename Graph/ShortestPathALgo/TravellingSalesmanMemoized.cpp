#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int TSP_DP(vector<vector<int>> &dist, int selectCity, int city, int n, vector<vector<int>> &dpArr)
{
    if (selectCity == (1 << n) - 1)
    {
        return dist[city][0];
    }

    if (dpArr[selectCity][city] != -1)
    {
        return dpArr[selectCity][city];
    }

    int ans = INT_MAX;

    for (int choice = 0; choice < n; choice++)
    {
        if ((selectCity & (1 << choice)) == 0)
        {
            int partialAns = dist[city][choice] + TSP_DP(dist, (selectCity | (1 << choice)), choice, n, dpArr);
            ans = min(partialAns, ans);
        }
    }
    return dpArr[selectCity][city] = ans;
}

int main()
{
    vector<vector<int>> dist = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}};

    int n = 4;
    vector<vector<int>> dpArr((1 << n), vector<int>(n , -1));
    cout << TSP_DP(dist, 1, 0, n, dpArr) << endl;
}