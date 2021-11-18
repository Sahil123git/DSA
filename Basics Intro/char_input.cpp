#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    char ch;
    cout << "Press a character and press return: ";
    cin >> ch;
    cout << ch;
    return 0;
}