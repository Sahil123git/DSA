#include <iostream>
using namespace std;
int main()
{
    int i = 0, j = 20, k;
    k = i-- - i++ + --j - ++j + --i - i-- + j++;
    cout << "i=" << i << " j=" << j << " k=" << k;
    return 0;
}
