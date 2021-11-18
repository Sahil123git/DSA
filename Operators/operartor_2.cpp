#include <iostream>
using namespace std;
int main()
{
    int a=2;
    a = 3 * (a--);
    cout << a;
    return 0;
}