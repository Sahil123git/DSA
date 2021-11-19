#include <bits/stdc++.h> ////https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1#
using namespace std;
class Solution
{
public:
    int doUnion(int arr1[], int n, int arr2[], int m)
    {
        int hsh_arr1[100003] = {0};
        int i = 0, j = 0, k = 0, arr[n + m] = {-1};
        int count1 = 0;
        while (i < n && j < m)
        {
            if (arr1[i] == arr2[j])
            {
                if (hsh_arr1[arr1[i]] == 0)
                {
                    hsh_arr1[arr1[i]] = 1;
                    arr[k++] = arr1[i++];
                    count1++;
                    j++;
                }
                else
                {
                    j++;
                    i++;
                }
            }
            else if (arr1[i] < arr2[j])
            {
                if (hsh_arr1[arr1[i]] == 0)
                {
                    hsh_arr1[arr1[i]] = 1;
                    arr[k++] = arr1[i++];
                    count1++;
                }
                else
                {
                    i++;
                }
            }
            else if (arr1[i] > arr2[j])
            {
                if (hsh_arr1[arr2[j]] == 0)
                {
                    hsh_arr1[arr2[j]] = 1;
                    arr[k++] = arr2[j++];
                    count1++;
                }
                else
                {
                    j++;
                }
            }
        }
        if (i < n)
        {
            for (; i < n; i++)
            {
                if (hsh_arr1[arr1[i]] == 0)
                {
                    hsh_arr1[arr1[i]] = 1;
                    arr[k++] = arr1[i];
                    count1++;
                }
            }
        }
        if (j < m)
        {
            for (; j < m; j++)
            {
                if (hsh_arr1[arr2[j]] == 0)
                {
                    hsh_arr1[arr2[j]] = 1;
                    arr[k++] = arr2[i];
                    count1++;
                }
            }
        }
        // for(auto it:arr)
        // {
        //     cout<<it<<" ";
        // }
        return count1;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];
        Solution ob;
        cout << ob.doUnion(a, n, b, m) << endl;
    }
    return 0;
}