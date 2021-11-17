#include <iostream>
#include <queue>
using namespace std;
void mysort(int arr[], int n)
{
    priority_queue<int> q{arr, arr + n};
    for (int i = n - 1; i >= 0; i--)
    {
        arr[i] = q.top();
        q.pop();
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
    mysort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}