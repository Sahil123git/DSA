#include <iostream> //https://practice.geeksforgeeks.org/problems/maximize-number-of-toys/1/?track=cip-priority-queue&batchId=238#
#include <queue>
using namespace std;
int max_item(int arr[], int n, int amt_mny)
{
    priority_queue<int, vector<int>, greater<int>> q{arr, arr + n};
    int count = 0;
    while (amt_mny >= 0 && q.empty() != true && q.top() <= amt_mny)
    {
        amt_mny = amt_mny - q.top();
        // cout << q.top() << " "; //for checking
        q.pop();
        count++;
    }
    return count;
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
    int amt_mny;
    cin >> amt_mny;
    cout << max_item(arr, n, amt_mny);
    return 0;
}