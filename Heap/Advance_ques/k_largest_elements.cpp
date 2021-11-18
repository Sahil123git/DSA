#include <iostream> //O(NlogK)
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> kLargest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq; //MIN_HEAP
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<int> ans;
    while (!(pq.empty()))
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans;
    ans = kLargest(arr, n, k);
    for (auto it : ans)
    {
        cout << it << " ";
    }
}