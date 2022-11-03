#include <bits/stdc++.h>
using namespace std;
int n = 100000;
int pf[100001];
void Sieve()
{
    for (int i = 1; i <= n; i++) // initially all arr ele filled with by themselves
    {
        pf[i] = i;
    }
    for (int i = 2; i * i <= n; i++) // we'll mark till i*i <= n becoz if a num's square is greater than n, it will start marking from n + 1 but we need till n.
    {
        if (pf[i] == i) // these are prime num which will mark other nums
        // cur i can mark nums from (i*i till n)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (pf[j] == j) // can mark only when it is not marked by anyone else
                {
                    pf[j] = i;
                }
            }
        }
    }
}

int main()
{
    Sieve();
    int n = 1024;

    int nm = n;
    while (nm != 1) // O(log n)
    {
        cout << pf[nm] << " ";
        nm = nm / pf[nm];
    }
    cout << endl;

    // prime factors with no duplicates
    int prev = -1;
    while (n != 1)
    {
        if (prev != pf[n])
        {
            cout << pf[n] << " ";
        }
        prev = pf[n];
        n = n / pf[n];
    }
}

// DRY RUN
/*for nm = 15
    pf[15] is having 3
    15 / 3 = 5
    pf[5] is having 5
    5 / 5 = 1
    so stop
    Prime factors are  {3, 5}
*/
