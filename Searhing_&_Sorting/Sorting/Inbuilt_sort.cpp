#include <iostream>
#include <algorithm>
using namespace std;
bool comparator(int a, int b)
{
    return a > b;
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
    sort(arr, arr + n); //normal Sorting
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int n1;
    cin >> n1;
    int arr1[n];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    sort(arr1, arr1 + n1, comparator); //Rev sorting
    for (int i = 0; i < n1; i++)
    {
        cout << arr1[i] << " ";
    }
}