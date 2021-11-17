#include <iostream>
#include <queue>
using namespace std;
void mysort(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> q{arr, arr + n};
    for (int i = k; i < n; i++)
    {
        q.pop();
    }
    while (q.empty() != true)
    {
        cout << q.top() << " ";
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
    int k;
    cin >> k;
    mysort(arr, n, k);
}