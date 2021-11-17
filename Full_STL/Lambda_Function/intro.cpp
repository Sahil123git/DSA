#include <iostream>
using namespace std;
int main()
{
    auto it = [](int x, int y)
    { return x + y; }(1, 2);
    cout << it << endl;

    auto it_1 = [](int x, int y)
    { return x + y; };
    cout << it_1(1, 2);
    return 0;
}