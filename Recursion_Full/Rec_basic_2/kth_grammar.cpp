#include <iostream>
#include <cmath>
using namespace std;
int kth_gr(int n, int k)
{
    if (n == 1 && k == 1)
    {
        return 0;
    }
    int mid = (pow(2, n - 1)) / 2;
    if (mid >= k)
    {
        return kth_gr(n - 1, k);
    }
    else
    {
        return !kth_gr(n - 1, k - mid);
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << kth_gr(n, k);
    return 0;
}