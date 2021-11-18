#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cin.get();
    string str, big_str;
    int big_len = 0;
    while (n--)
    {
        getline(cin, str);
        if (str.length() > big_len)
        {
            big_len = str.length();
            big_str = str;
        }
    }
    cout << big_str;
}