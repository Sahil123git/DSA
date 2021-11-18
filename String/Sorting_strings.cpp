#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
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

    sort(str, str + n);

    for (int i = 0; i < n; i++)
    {
        cout << str[i] << endl;
    }
    return 0;
}