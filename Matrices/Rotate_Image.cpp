#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void rotate_rev(int arr[][100], int n, int m)
{
    for (int i = 0; i < n; i++) //1st reverse the whole array
    {
        int k = m - 1, j = 0;
        while (k > j)
        {
            swap(arr[i][j], arr[i][k]);
            j++;
            k--;
        }
    }
    for (int i = 0; i < n; i++) //then swap to do transpose
    {
        for (int j = 0; j < m; j++)
        {
            if (j > i)
            {
                swap(arr[i][j], arr[j][i]);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    rotate_rev(arr, n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}