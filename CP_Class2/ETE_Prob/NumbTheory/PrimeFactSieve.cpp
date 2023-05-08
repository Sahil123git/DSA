#include <bits/stdc++.h>
using namespace std;
#define int long long
int n = 100000;
int pf[100001];

void Sieve()
{
    // cout << "her";
    for (int i = 1; i <= n; i++)
    {
        pf[i] = i;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (pf[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (pf[j] == j)
                {
                    // cout << "hh";
                    pf[j] = i;
                }
            }
        }
    }
}

void fillArr(vector<pair<int, int>> &vc) // finding fst and lst prime factor of every num
{
    for (int i = 1; i <= 100000; i++)
    {
        int ind = i, fstp = pf[ind], scndp = pf[ind];

        while (ind != 1)
        {
            scndp = pf[ind];
            ind = ind / pf[ind];
        }
        vc[i] = {fstp,
                 scndp};

        cout << vc[i].first << " " << vc[i].second << endl;
    }
}

void soln(vector<pair<int, int>> &vc)
{
    int st, end, p;
    cin >> st >> end >> p;
    int cnt = 0;

    for (int i = st; i <= end; i++)
    {
        int fstFctr = vc[i].first, scndFctr = vc[i].second;

        if (fstFctr <= p && scndFctr <= p)
        {
            cnt++;
        }
    }
    cout << cnt;
}
int32_t main()
{
    int t;
    cin >> t;
    vector<pair<int, int>> vc(100001, {0, 0}); // will be having fst and last prime factor of a num

    Sieve();

    fillArr(vc);

    while (t--)
    {
        soln(vc);
        cout << endl;
    }
}