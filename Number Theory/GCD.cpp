#include <iostream>
#include <algorithm>
using namespace std;
int naive_gcd(int a, int b) // O(n)
{
    int ans = 1; // if both num are not div
    for (int i = 2; i <= min(a, b); i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            ans = i;
        }
    }
    return ans;
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

int euclid_gcd_rec(int a, int b) // O(Log n)
{
    if (b == 0) // or can write (rem(a%b)==0) then return b
    {
        return a;
    }
    return euclid_gcd_rec(b, a % b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << naive_gcd(a, b) << endl;
    cout << euclid_gcd_iter(a, b) << endl;
    cout << euclid_gcd_rec(a, b) << endl;
    cout << __gcd(a, b) << endl;

    cout << "LCM: " << (a * b) / __gcd(a, b);
}