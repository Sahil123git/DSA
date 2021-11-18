#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << INT_MAX << endl;

    int a = (1LL << 32) - 1;
    cout << a << " " << ~(0) << endl; //this will overload as all 32 bits are set

    int c = (1LL << 31) - 1; //but this will not as in this 31 bits are set
    cout << c << endl;

    unsigned int b = (1LL << 32) - 1; //in this we are using unsigned so it will not oveerload even in 32 also
    cout << b << endl;

    return 0;
}