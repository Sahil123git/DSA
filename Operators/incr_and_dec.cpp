#include <iostream>
using namespace std;
int main()
{
    int a = 1;
    a = --a + a++;
    cout << a;
    return 0;
}