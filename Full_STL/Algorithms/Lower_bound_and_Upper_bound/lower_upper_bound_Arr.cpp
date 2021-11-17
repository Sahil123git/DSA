#include <iostream> //TIME COMPLEXITY O[logN] of upper and lower bound
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
    sort(arr, arr + n);
    int *ptr1 = lower_bound(arr, arr + n, 2);
    int *ptr2 = upper_bound(arr, arr + n, 2);
    cout << *ptr1 << " lower bound" << endl;
    cout << *ptr2 << " upper bound" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}