#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> pr;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            pr.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        pr.push_back(n);
    }
    for (auto it : pr)
    {
        cout << it << " ";
    }
}
int main()
{
    solve();
}