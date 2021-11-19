#include <iostream>
using namespace std;
int Bin_sea(int n, int key, int arr[])
{
    int low, high;
    low = 0;
    high = n - 1;
    while (high >= low)
    {
        int mid = (low + (high - low) / 2);
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
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
    cout << Bin_sea(n, key, arr);
}