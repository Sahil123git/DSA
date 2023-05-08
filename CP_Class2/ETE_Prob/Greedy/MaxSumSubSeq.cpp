#include <bits/stdc++.h>
using namespace std;

int fndSubSeqSum(vector<int> &vc, int n, int ind, int sum)
{
    if (ind < 0)
    {
        return sum;
    }

    return max(fndSubSeqSum(vc, n, ind - 1, vc[ind] + sum), fndSubSeqSum(vc, n, ind - 1, sum));
}
int main()
{
    int n;
    cin >> n;

    vector<int> vc(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
    }

    cout << fndSubSeqSum(vc, n, n - 1, 0);
}