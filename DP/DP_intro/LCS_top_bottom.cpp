#include <iostream> //Longest Common Subsequence
#include <vector>
using namespace std;
int lcs_fndr(string str1, string str2, int i, int j, vector<vector<int>> &dp_arr)
{
    if (i == str1.size() || j == str2.size()) // base case
    {
        return dp_arr[i][j] = 0;
    }
    if (dp_arr[i][j] != -1) // dp arr chkng case
    {
        // cout << "sd" << endl;
        return dp_arr[i][j];
    }

    if (str1[i] == str2[j]) // when both str1 and str2 char are same
    {
        return dp_arr[i][j] = 1 + lcs_fndr(str1, str2, i + 1, j + 1, dp_arr);
    }

    int optn1, optn2; // when both strings chars are not same

    optn1 = lcs_fndr(str1, str2, i + 1, j, dp_arr); // here we'll chk inc(i+1) with old j
    optn2 = lcs_fndr(str1, str2, i, j + 1, dp_arr); // here we'll chk inc(j+1) with old i
    return dp_arr[i][j] = max(optn1, optn2);
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    vector<vector<int>> dp_arr(str1.size() + 1, vector<int>(str2.size() + 1, -1));

    int i = 0, j = 0;
    cout << lcs_fndr(str1, str2, i, j, dp_arr) << endl;

    // for (auto it : dp_arr)//to see how it is wrkng
    // {
    //     for (auto itt : it)
    //     {
    //         cout << itt << " ";
    //     }
    //     cout << endl;
    // }
}
// we can chk our ans in dp arr at dp_arr[0][0] becoz this is strtng call values