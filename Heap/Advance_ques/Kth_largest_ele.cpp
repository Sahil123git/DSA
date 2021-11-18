#include <iostream> //O(NlogK)
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> min_pq;
    for (int i = 0; i < nums.size(); i++)
    {
        min_pq.push(nums[i]);
        if (min_pq.size() > k)
        {
            min_pq.pop();
        }
    }
    return min_pq.top();
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vt;

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        vt.push_back(ele);
    }
    int ans;
    ans = findKthLargest(vt, k);
    cout << ans;
}