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

int inv(int a)
{
    return powr(a, mod - 2); // usng Little Format's theorem
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
    string text = "sahilabsahil", pattern = "ab";
    int n = text.size(), m = pattern.size();

    int pat_hash = poly_hash_string(pattern);
    int text_hash = poly_hash_string(text.substr(0, m)); // poly hash of 1st m strings

    if (text_hash == pat_hash && pattern == text.substr(0, m))
    {
        cout << "0\n";
    }

    for (int i = 1; i + m <= n; i++)
    {
        int new_hash = text_hash;

        // 1st Step removing [i-1]th character
        new_hash = (new_hash - (text[i - 1] - 'a' + 1) + mod) % mod;

        // 2nd Step multiplying new_hash with inv of prime, to dec by power 1
        new_hash *= inv(p);
        // new_hash %= mod;//own choice becoz this part is done by inv func

        // 3rd Step now adding last char to new_hash
        new_hash = new_hash + (text[i + m - 1] - 'a' + 1) * powr(p, m - 1);
        new_hash %= mod; // own choice bec this is part is done by powr func also

        if (new_hash == pat_hash && pattern == text.substr(i, m))
        {
            cout << i << "\n";
        }
        text_hash = new_hash;
    }
}