#include <iostream>
#include <algorithm>
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

    bool present = binary_search(arr, arr + n, key);
    cout << present << " ";

    int *lb = lower_bound(arr, arr + n, key);
    cout << lb - arr << " ";

    auto ub = upper_bound(arr, arr + n, key);
    cout << ub - arr << endl;

    cout << (ub - lb) << endl;

    return 0;
}