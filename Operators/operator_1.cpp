#include <iostream>
using namespace std;
int main()
{
    int a = 1, b = 3, c;
    c = b << a; //c=6
    b = c * (b * (++a)--);
    a = a >> b;
    cout << b << " " << a;
    return 0;
}