/*Give max product of subarray
[-1, -2, -3, 4, 5, 0]
*/
// Max and Min Subsequence
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1, -2, -3, 0, 4, -5, 0}; // TC: O(n), SC: O(1)
    int n = sizeof(a) / sizeof(a[0]);
    if (n == 1)
    {
        cout << a[0] << endl;
        return 0;
    }

    int countNegative = 0, countPositive = 0;
    int countZero = 0, positiveProduct = 1;
    int negativeProduct = 1, Min = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            countZero++;
        }
        else if (a[i] < 0)
        {
            countNegative++;
            negativeProduct = negativeProduct * a[i];
            Min = min(Min, abs(a[i])); // saving min negative num
        }
        else
        {
            countPositive++;
            positiveProduct = positiveProduct * a[i];
        }
    }

    if (countZero == n)
    {
        cout << 0 << endl;
    }

    if (countZero == n - 1 && countNegative == 1 && countZero != 0)
    {
        cout << 0 << endl;
    }
    else if (countNegative % 2 == 0) // if count of neg num are even
    {
        cout << positiveProduct * negativeProduct << endl;
    }
    else
    {
        cout << positiveProduct * (negativeProduct / (-Min)); // dividing by (-Min) to remove smallest -ve num
    }
    return 0;
}

/*[-1]*/