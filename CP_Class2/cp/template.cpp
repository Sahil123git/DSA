#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define fo(i, n) for (int i = 0; i < n; i++)
#define forab(i, a, b) for (int i = a; i < b; i++)
#define foe(n) for (auto it : n)
#define int long long
#define ll long long
#define pb push_back
#define eb emplace_back
#define m 1000000007

typedef vector<int> vi;
typedef pair<char, char> pi;
typedef vector<pi> vpi;
typedef pair<ll, ll> pl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

string int_to_str(int num)
{
    string str;
    stringstream ss;
    ss << num;
    ss >> str;

    return str;
}

int str_to_int(string str)
{
    int num = 0;
    stringstream ss(str);
    ss >> num;

    return num;
}
string toBinary(int num) // cnvrtng decimal to bin string
{
    string ansBin;
    while (num != 0)
    {
        ansBin += (to_string(num % 2));
        num = num / 2;
    }
    reverse(ansBin.begin(), ansBin.end());
    return ansBin;
}

int euclid_gcd_iter(int a, int b) // O(log n)
{
    int rem = a % b, ans;
    while (rem != 0)
    {
        a = b;
        b = rem;
        rem = a % b;
    }
    return b;
}
// binary expo
int chk_pwr_iter(int num, int pow) // iterative  TC:O(log pow)
{
    int res = 1;
    while (pow)
    {
        if (pow & 1) // if last bit is set
        {
            res = (1ll * res * num) % m; // if bit is set then storing in res
        }
        num = (num * 1ll * num) % m; // mul num with num
        pow = pow >> 1;              // right shifting pow
    }
    return res;
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
    for (int i = 5; i * i <= n; i = i + 6) // starting from 5 and add 6 will always reach 1 before of 6a2 multiple
    {
        if ((n % i == 0) || (n % (i + 2) == 0)) // we are chkng using (6n-1) and (6n+1)
        {                                       // becoz these num can only be prime or
            return false;                       // not and we are chkng from smallest
        }                                       // prime num and we also know tht every
    }                                           // num smallest factor is always prime
                                                // num. If num is prime then it will not get divisible by any smallest prime num
    return true;
}

// sieve of Eros
void fnd_sieve(int n)
{
    int sieveArr[100000] = {0};    // make this global if want to use this fun
    for (int i = 3; i < n; i += 2) // marking all odds as 1, except 2 all even can't be prime number
    {
        sieveArr[i] = 1;
    }

    for (int i = 3; i < n; i += 2) // marking all multiple of i as 0
    {
        if (sieveArr[i] == 1)
        {
            // initailly j will be i*i because smaller ele will get marked by smaller value of i
            for (int j = i * i; j < n; j += i) // iterating with speed of i
            {
                sieveArr[j] = 0;
            }
        }
    }
    sieveArr[2] = 1;               // becoz 2 is prime
    sieveArr[0] = sieveArr[1] = 0; // because 0 and 1 is not prime
}

// NcR (Binomial Distribution)
int ncr(int N, int r) // NcR DP TC : O(n^2)
{
    int dpArr[N + 1][r + 1];
    // memset(dpArr, -1, sizeof(dpArr));

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= r; j++)
        {
            if (j > i)
            {
                dpArr[i][j] = 0;
            }
            else if (j == 0 || j == i)
            {
                dpArr[i][j] = 1;
            }
            else
            {
                dpArr[i][j] = dpArr[i - 1][j - 1] + dpArr[i - 1][j];
            }
        }
    }
    // cout << dpArr[2][0] << endl;
    return dpArr[N][r];
}

// for finding Factors
int fndFactors(int num) // TC:O(sqrt(N))
{
    int i = 1, cntFctr = 0;
    // cout << num << endl;
    // vi vc; //This vector is having all factors of num
    // in this vector we are adding divisor and quotient
    while (i * i <= num)
    {
        if (num % i == 0)
        {
            cntFctr++;
            // vc.pb(i);

            if (num / i != i) // if divisor is a factor then quotient will also be factor
            {                 // this if case when num is 16 divisor is 4, then quotient will also be 4
                cntFctr++;
                // vc.pb(num / i);
            }
        }
        i++;
    }
    return cntFctr;
}

int sqrtNum(int num) // TC:log(n)
{
    int low = 1, high = num;
    int ans;
    while (low <= high)
    {
        int mid = low - (low - high) / 2;
        if (mid * mid == num)
        {
            return mid;
        }
        else if (mid * mid <= num)
        {
            ans = mid; // when smaller, then only we can take this. It is like floor
            low = mid + 1;
        }
        else // eg if num=10 but mid is 5 which will give 25 so don't take
        {
            high = mid - 1;
        }
    }

    return ans;
}
//---------------Main_Code-----------------------------------------

void yes_i_will_solve()
{
}

//----------------------------------------------------------------
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        // cout << "hi";
        yes_i_will_solve();
        cout << endl;
    }
    return 0;
}
