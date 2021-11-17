#include <iostream>
using namespace std;
int lin_sea(int n, int arr[], int k)
{
    if (n == 0)
    {
        return -1;
    }
    if (arr[0] == k)
    {
        return 0;
    }
    int ind = lin_sea(n - 1, arr + 1, k);
    if (ind == -1)
    {
        return -1;
    }
    return ind + 1;
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
    cout << lin_sea(n, arr, key);
    return 0;
}