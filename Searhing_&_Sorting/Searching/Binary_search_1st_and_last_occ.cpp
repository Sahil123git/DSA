#include <iostream>
using namespace std;
int first_occ(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1, ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1; //this is imp step
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
int last_occ(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1, ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
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
    cout << first_occ(arr, n, key) << endl;
    cout << last_occ(arr, n, key);
    return 0;
}