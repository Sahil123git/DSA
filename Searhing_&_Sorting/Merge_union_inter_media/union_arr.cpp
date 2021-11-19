#include <iostream> //https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1#
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int t = m + n;
    int arr1[n], arr2[m], arr[t] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            arr[k++] = arr1[i++];
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            arr[k++] = arr1[i++];
        }
        else if (arr1[i] > arr2[j])
        {
            arr[k++] = arr2[j++];
        }
    }
    if (i < n)
    {
        for (; i < n; i++)
        {
            arr[k++] = arr1[i];
        }
    }
    if (j < m)
    {
        for (; j < m; j++)
        {
            arr[k++] = arr2[j];
        }
    }
    for (auto it : arr)
    {
        cout << it << " ";
    }
}