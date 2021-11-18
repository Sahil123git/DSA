#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cin >> n >> i;
    i = 1 << i - 1;
    cout << (n ^ i) << endl;
    return 0;
}