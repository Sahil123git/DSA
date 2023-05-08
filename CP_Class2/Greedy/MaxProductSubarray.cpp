/*
[1,2,3,4,0,5,6]

 */
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main()
{
    vector<int> vc{1, 2, -3, 5 - 2};
    int n = vc.size();
    cout << vc[0];
    int maxi = INT_MIN, prdct = 1;
    for (int i = 0; i < n; i++)
    {
        if (vc[i] <= 0)
        {
            prdct = 1;
        }
        else
        {
            prdct *= vc[i];
        }
        maxi = max(vc[i], prdct);
    }

    prdct = 1, maxi = INT_MIN;
    for (int i = n; i >= 0; i--)
    {
        if (vc[i] <= 0)
        {
            prdct = 1;
        }
        else
        {
            prdct *= vc[i];
        }
        maxi = max(vc[i], prdct);
    }
}