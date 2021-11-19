#include <iostream>
using namespace std;
void insertion(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int ele = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > ele)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = ele;
    }
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
    insertion(arr, n);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}