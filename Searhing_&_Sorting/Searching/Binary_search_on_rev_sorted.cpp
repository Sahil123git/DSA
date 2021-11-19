#include <iostream>
using namespace std;
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
    int low, high;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        int mid = (low + (high - low) / 2); //this is imp as this can handle overflow of integer
        if (arr[mid] == key)
        {
            cout << "found at " << mid << endl;
            return 0;
        }
        else if (key < arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "not found " << endl;
    return 0;
}