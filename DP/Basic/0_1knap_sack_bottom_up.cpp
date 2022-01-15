#include <iostream> //https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1# and YT Aditya vrma
#include <vector>
using namespace std;
int main()
{
    int n, cpty;
    cin >> n >> cpty;

    vector<int> values, weight;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        values.push_back(ele);
    }
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        weight.push_back(ele);
    }
    vector<vector<int>> dp_arr(cpty + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < cpty + 1; i++) // i:cpty
    {
        for (int j = 0; j < n + 1; j++) // j:n
        {
            if (i == 0 || j == 0) // base case of top down dp
            {
                dp_arr[i][j] = 0;
            }
            else if (weight[j - 1] <= i) // 2nd case of top down dp
            {
                dp_arr[i][j] = max((values[j - 1] + dp_arr[i - weight[j - 1]][j - 1]), dp_arr[i][j - 1]);
            }
            else if (weight[j - 1] > i) // 3rd case when weight[j-1] is greater than cpty
            {
                dp_arr[i][j] = dp_arr[i][j - 1];
            }
        }
    }
    for (auto it : dp_arr) // to see how it is filling dp_arr
    {
        for (auto iit : it)
        {
            cout << iit << " ";
        }
        cout << endl;
    }
    cout << dp_arr[cpty][n];
}
/*3 num of values and weight
4 bag cpty
1 2 3 values
4 5 1 their weight*/
// we have to find how we can fill this is bag with max values