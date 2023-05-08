#include <bits/stdc++.h>
using namespace std;

long long gpf(int n)
{
    long long ans = -1;
    while (n % 2 == 0)
    {
        ans = 2;
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            ans = i;
            n = n / i;
        }
    }
    if (n > 2)
        ans = n;
    return ans;
}

long long jagged(int n)
{
    if (n % 2 == 0)
        return 2;
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
            return i;
    }
    return n;
}
int main()
{

    int gpfArr[100001] = {};
    int jaggedArr[100001] = {};

    for (int i = 1; i <= 100000; i++)
    {
        gpfArr[i] = gpf(i);
    }
    for (int i = 1; i <= 100000; i++)
    {
        jaggedArr[i] = jagged(i);
    }
    int t;
    cin >> t;
    while (t--)
    {
        int s, e, p;
        cin >> s >> e >> p;
        int count = 0;
        for (int i = s; i <= e; i++)
        {
            if (gpfArr[i] <= p && jaggedArr[i] <= p)
                count++;
        }
        if (count != 0)
            cout << count << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}