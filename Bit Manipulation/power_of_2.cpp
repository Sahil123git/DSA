#include <iostream>
using namespace std;
int main()
{
    int n, chk;
    cin >> n;
    if (n == 0)
    {
        cout << "not power of 2";
        return 0;
    }
    chk = n - 1;
    (n & chk) ? cout << "not power of 2" : cout << "power of 2";
    return 0;
}