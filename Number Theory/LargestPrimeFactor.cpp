/*Chkng  whether a num largest and smallest prime factors are smaller than p*/
/*Test case Eg
1
1 100000 200

here t = 1
st = 1, end = 100000, p = 200
find all num inclusive st and end whose smallest prime factor and largest prime factor <= p

*/
#include <bits/stdc++.h>
using namespace std;
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
    }
}

void fillLargestPFctrArr(vector<int> &vc) // finding largest prime factors
{
    for (int i = 1; i <= 100000; i++)
    {
        int ind = i, grtp = pf[ind];

        while (ind != 1)
        {
            grtp = pf[ind];
            ind = ind / pf[ind];
        }
        vc[i] = grtp;
    }
}

int main()
{
    int t;
    cin >> t;
    vector<pair<int, int>> vc(100001, {0, 0}); // will be having fst and last prime factor of a num
    vector<int> lrgstPrimeFctr(100001, 0);

    Sieve();

    fillArr(vc);                         // fill largest and smallest prime factor arr
    fillLargestPFctrArr(lrgstPrimeFctr); // fill largest prime factor arr
    // for (auto it : lrgstPrimeFctr)
    // {
    //     cout << it << " ";
    // }
    while (t--)
    {
        soln(vc);
        cout << endl;
    }
}