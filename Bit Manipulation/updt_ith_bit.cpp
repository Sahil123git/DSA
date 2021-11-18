#include <iostream>
using namespace std;
int main()
{
    int n, i, bit;
    cin >> n >> i >> bit;
    int ele = 1;
    ele = ~(ele << (i - 1)); //use brackets carefully otherwise bit manipulation can cause errors

    ele = ele & n;                            // we will use this we are changing 1 to 0
    cout << (ele | (bit << (i - 1))) << endl; //we will use this we are changing 0 to 1
    return 0;
}