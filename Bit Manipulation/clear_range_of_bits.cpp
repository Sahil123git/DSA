#include <iostream>
using namespace std;
int main()
{
    int n, i, j;
    cin >> n >> i >> j;
    int ele_a = (n & (-1 << j));
    int ele_b = ((1 << (i - 1)) - 1);
    cout << (ele_a | ele_b) << endl;
    return 0;
}