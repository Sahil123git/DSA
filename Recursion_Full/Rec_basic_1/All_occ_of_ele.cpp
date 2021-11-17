#include <iostream>
using namespace std;
void sea_occ(int arr[], int n, int i, int k)
{
    if (i == n)
    {
        return;
    }
    if (arr[i] == k)
    {
        cout << i << " ";
    }
    return sea_occ(arr, n, i + 1, k);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;

    sea_occ(arr, n, 0, key);
    return 0;
}