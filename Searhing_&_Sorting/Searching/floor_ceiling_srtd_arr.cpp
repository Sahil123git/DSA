#include <iostream>
using namespace std;
int Bin_sea_ceiling(int n, int key, int arr[])
{
    int low, high;
    if (key > arr[n - 1]) //edge cases
    {
        return -1;
    }
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
    return low;
}
int Bin_sea_floor(int n, int key, int arr[])
{
    if (key < arr[0]) //edge cases
    {
        return -1;
    }
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
    return high;
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

    cout << Bin_sea_ceiling(n, key, arr) << " ceilings" << endl;
    cout << Bin_sea_floor(n, key, arr) << " foor" << endl;

    return 0;
}