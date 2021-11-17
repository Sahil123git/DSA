#include <iostream>
using namespace std;
bool bin_sea(int arr[], int k, int low, int high)
{
    if (low > high)
    {
        return 0;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == k)
    {
        return 1;
    }
    if (arr[mid] < k)
    {
        low = mid + 1;
    }
    else if (arr[mid] > k)
    {
        high = mid - 1;
    }
    return bin_sea(arr, k, low, high);
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
    cout << bin_sea(arr, key, 0, n - 1);
}