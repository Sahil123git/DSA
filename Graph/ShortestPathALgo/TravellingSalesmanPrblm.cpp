#include <iostream>
#include <vector>
#include <climits>

using namespace std; // from Udemy Graph course
int tsp(vector<vector<int>> &dist, int setOfCities, int choosenCity, int n)
{
    if (setOfCities == (1 << n) - 1) // this will chk whether we reached all one condn like (111..) which is base condn
    {
        return dist[choosenCity][0]; // will return dist from choosen city to 0 (so tht we can come back to start city)
    }

    int ans = INT_MAX;
    for (int choice = 0; choice < n; choice++) // chkng using bit manipulation cnpt
    {
        if ((setOfCities & (1 << choice)) == 0)
        {
            int SubAns = dist[choosenCity][choice] + tsp(dist, ((1 << choice) | setOfCities), choice, n); // we have to go from (choosenCity to choice) (so find dist also from choosenCity to choice) and now from choice u will go to next destination so pass choice to func

            ans = min(SubAns, ans);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> dist = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}};

    cout << tsp(dist, 1, 0, 4) << endl;
}
