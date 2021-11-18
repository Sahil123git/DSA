#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cin >> n >> i;
    int ele = (-1 << i); //this -1 is all 1 (i.e 2^32)
    cout << (ele & n) << " ";
    return 0;
}