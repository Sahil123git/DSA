#include <iostream>
#define int long long int
const int mod = 1e9 + 7;
const int p = 31; // prime num greater than total alphabets num
using namespace std;
int powr(int num, int pow)
{
    int res = 1;
    while (pow)
    {
        if (pow & 1)
        {
            res = (res * num) % mod;
        }
        num = (num * num) % mod;
        pow = pow >> 1;
    }
    return res;
}
int poly_hash_string(string s) // Hash Func
{
    int p_pwr = 1, hash_val = 0;

    for (int i = 0; i < s.size(); i++)
    {
        hash_val += (p_pwr * (s[i] - 'a' + 1));
        p_pwr = (p_pwr * p) % mod;
        hash_val %= mod;
    }
    return hash_val;
}

int32_t main()
{
    string text = "sabsabl", pattern = "ab";
    int n = text.size(), m = pattern.size();

    int pat_hash = poly_hash_string(pattern);
    int pref[n];

    for (int i = 0; i < n; i++) // here we are adding sum of all ele to i
    {
        pref[i] = (text[i] - 'a' + 1) * powr(p, i);
        pref[i] %= mod;
    }

    for (int i = 1; i < n; i++) // here we are setting sum of all prefix ele to i ele of arr
    {
        pref[i] += pref[i - 1];
        pref[i] %= mod;
    }

    for (int i = 0; i + m <= n; i++)
    {
        int new_hash = pref[i + m - 1];
        // m will take i to 1st step more so dec by 1
        if (i - 1 >= 0)
        {
            new_hash -= pref[i - 1];
        }
        new_hash += mod; // subtracting so usng Modular Arth prop for subtraction
        new_hash %= mod;

        if (new_hash == (pat_hash * powr(p, i) % mod))
        {
            cout << i << "\n";
        }
    }
}