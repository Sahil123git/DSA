// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
bool maze(vector<vector<int>> mv, int v[][8], vector<string> &ans, int i, int j, int m, int n)
{
    string str;
    if (i == m && j == n)
    {
        v[m][n] = 1;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << v[i][j] << " "; //it will print the valid path

                if (j == 0 && i != 0 && v[i][j] == 1)
                {
                    str.push_back('D');
                }
                else if (j != 0 && v[i][j - 1] == 0 && v[i][j] == 1)
                {
                    str.push_back('D');
                }
                else if (v[i][j] == 1 && (i != 0 || j != 0))
                {
                    str.push_back('R');
                }
            }
            cout << endl;
        }
        cout << endl;
        ans.push_back(str);
        return 1;
    }
    if (i > m || j > n)
    {
        return false;
    }
    if (mv[i][j] == 0)
    {
        return false;
    }
    v[i][j] = 1;
    bool right = maze(mv, v, ans, i, j + 1, m, n);
    bool left = maze(mv, v, ans, i + 1, j, m, n);
    v[i][j] = 0;
    if (right || left)
    {
        return 1;
    }
    return 0;
}
class Solution
{
public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        int v[8][8] = {0};
        if (m[n - 1][n - 1] == 0)
        {
            return ans;
        }
        // vector<vector<int>> v={0};
        maze(m, v, ans, 0, 0, n - 1, n - 1);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends