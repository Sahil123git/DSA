/*
6: 1 * 2 * 3
12: 1 * 2 * 2 * 3
GCD: 6

17: 1 * 17
25: 1 * 5 * 6
GCD: 1
*/

#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }

    return (b % a, a);
}

int main()
{
    cout << gcd(6, 12);
}