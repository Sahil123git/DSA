#include <iostream>
using namespace std;
int ladder_prob(int n, int k)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    int count = 0;
    for (int i = 1; i <= k; i++)
    {
        count += ladder_prob(n - i, k);
    }
    return count;
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << ladder_prob(n, k);
    return 0;
}