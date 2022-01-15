#include <iostream> //Top down approach using recusrion
using namespace std;
int fnd_fibo(int n, int dp[])
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != 0)
    {
        return dp[n]; // if it is not 0 means there is ele present in our hash arr
    }
    // if no ele is in hsh_arr then find hash arr for this ele
    int ans;
    ans = fnd_fibo(n - 1, dp) + fnd_fibo(n - 2, dp);
    return dp[n] = ans;
}
int main() 
{
    int dp[100] = {0};
    // vector<int> vt(100,0);
    int n;
    cin >> n;
    cout << fnd_fibo(n, dp);
    return 0;
}