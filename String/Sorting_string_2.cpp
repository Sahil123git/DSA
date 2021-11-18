#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool compare(string a, string b)
{
    if (a.length() == b.length())
    {
        return a < b;
    }

    // cout << a.length() << " " << a << " " << b.length() << " " << b << endl; // cout << "fd";
    return a.length() > b.length();
}
int main()
{
    int n;
    cin >> n;
    cin.get();
    string str[500];
    for (int i = 0; i < n; i++)
    {
        getline(cin, str[i]);
    }

    sort(str, str + n, compare);

    for (int i = 0; i < n; i++)
    {
        cout << str[i] << endl;
    }
    return 0;
}