#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n] = {1, 2, 4, 5}; //for array

    sort(arr, arr + n);

    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;

    int arr1[n] = {1, 5, 2, 3};
    sort(arr1 + 1, arr1 + 3); //for changing the order

    for (auto it : arr1)
    {
        cout << it << " ";
    }
    cout << endl;

    vector<int> v{1, 5, 2, 3}; //for vector
    sort(v.begin(), v.end());  //for changing the order

    for (auto it : v)
    {
        cout << it << " ";
    }
}