#include <bits/stdc++.h>
using namespace std;

void primeFctrFnd(int n) // sqrt(n)
{
    vector<int> pr;
    for (int i = 2; i * i <= n; i++) // TC: Sqrt(n)
    {
        bool chk = 1;
        while (n % i == 0)
        {
            if (chk == 1)
            {
                pr.push_back(i);
                chk = 0;
            }
            n /= i;
        }
    }
    if (n > 1) // left out prime num
    {
        // cout << n << endl;
        pr.push_back(n);
    }
    for (auto it : pr)
    {
        cout << it << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    primeFctrFnd(n);
}