#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    vector<int> vc{-10, -30, -4, -2, -5, 40};
    int n = vc.size(), maxi = INT_MIN, cur = 0;

    for (int i = 0; i < n; i++)
    {
        cur += vc[i];
        maxi = max(cur, maxi);
        if (cur < 0)
        {
            cur = 0;
        }
    }
    cout << maxi;
}