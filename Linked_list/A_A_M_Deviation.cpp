#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (int i = 0; i < n; i++)
#define for_ab(i, a, b) for (int i = a; i < b; i++)
#define foe(n) for (auto it : n)
#define ll long long
#define pb push_back
#define eb emplace_back

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<ll, ll> pl;

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

int gcd(int num1, int num2)
{
    if (num1 == 0 || num2 == 0)
    {
        return abs(num1 - num2);
    }
    while (num1 != num2)
    {
        if (num1 > num2)
        {
            num1 = num1 - num2;
        }
        else
        {
            num2 = num2 - num1;
        }
    }
    return num1;
}
//---------------Main_Code-----------------------------------------------------

void yes_i_will_solve()
{
    ll a, b, c;
    cin >> a >> b >> c;

    if ((a + c - 2 * b) % 3 == 0)
    {
        cout << "0";
    }
    else
    {
        cout << "1";
    }
}
//----------------------------------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        yes_i_will_solve();
        cout << endl;
    }
    return 0;
}
