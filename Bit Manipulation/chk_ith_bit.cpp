#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cin >> n >> i;
    int ele = 1;
    ele = (ele << i - 1);
    int chk = n & ele;
    // cout << chk << " ";
    (chk) ? cout << "already set" : cout << "not set";
    return 0;
}