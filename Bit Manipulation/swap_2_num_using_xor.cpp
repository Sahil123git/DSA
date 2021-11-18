#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    a = a ^ b; // a is having xor of both a and b
    b = a ^ b; // now we r doing xor of (a^b^b) this set b as a
    a = a ^ b; // now a is having a^b and b is having a so it set a as b

    cout << a << " " << b;
    return 0;
}