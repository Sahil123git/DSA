#include <iostream>
using namespace std;

unsigned int swapBits(unsigned int n)
{
    // Youri code here
    int ls = n << 1;
    int rs = n >> 1;

    rs = (rs & 0x55555555);
    ls = (ls & 0xAAAAAAAA);

    int ans = (ls | rs);

    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << swapBits(n);
    return 0;
}