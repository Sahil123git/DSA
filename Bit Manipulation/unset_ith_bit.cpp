#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int ele = 1;
    ele = ele << (k - 1); // to leftshift the bit
    ele = ~(ele);         //to flip the bits
    ele = ele & n;
    cout << ele;
}