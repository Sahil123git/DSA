#include <bits/stdc++.h>
using namespace std;

void primeFctrSieve(long long num)
{
    vector<pair<int, int>> vp;
    vp.push_back({-1, -1});

    for (int ind = 1; ind <= 1000005; ind++)
    {
        int n = ind;
        long long lrgPrime = n, smPrime = n;
        for (int i = 2; i * i <= n; i++)
        {
            bool val = false;
            while (n % i == 0)
            {
                if (smPrime == n)
                {
                    smPrime = i;
                }
                if (val == false)
                {
                    // cout << i << " ";
                    val = true;
                }
                lrgPrime = i;
                n = n / i;
            }
        }
        if (n > 1)
        {
            // cout << n << endl;
            lrgPrime = n;
        }

        // cout << lrgPrime << " " << smPrime << endl;
        vp.push_back({smPrime, lrgPrime});
    }
    cout << vp[num].first << " " << vp[num].second;
}

void primeFctr(long long n)
{
    long long lrgPrime = n, smPrime = n;
    for (int i = 2; i * i <= n; i++)
    {
        bool val = false;
        while (n % i == 0)
        {
            if (smPrime == n)
            {
                smPrime = i;
            }
            if (val == false)
            {
                // cout << i << " ";
                val = true;
            }
            lrgPrime = i;
            n = n / i;
        }
    }
    if (n > 1)
    {
        // cout << n << endl;
        lrgPrime = n;
    }

    cout << lrgPrime << " " << smPrime << endl;
}
bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n <= 3)
    {
        return true;
    }

    if (n % 2 == 0 || n % 3 == 0) // num which are divisible by 2 or 3 are also not prime
    {
        return false;
    }

    // 6n - 1 and 6n + 1 concept
    for (int i = 5; i * i <= n; i = i + 6)
    {
        if ((n % i == 0) || (n % (i + 2) == 0))
        {
            return false;
        }
    }

    return true;
}

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
    }
}

int main()
{
    int n;
    cin >> n;
    primeFctr(n);
    primeFctrSieve(n);
}