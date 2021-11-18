#include <iostream>//Leetcode:https://leetcode.com/problems/find-k-closest-elements/

#include <algorithm>
// #include <utility>
// #include <cmath>
#include <vector>
#include <queue>
using namespace std;

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    priority_queue<pair<int, int>> pq; //Max heap
    for (int i = 0; i < arr.size(); i++)
    {
        pq.push({abs(arr[i] - x), arr[i]});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<int> ans;
    while (!(pq.empty()))
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }
    int k1, k2;
    cin >> k1 >> k2;

    vector<int> ans;
    ans = findClosestElements(arr, k1, k2);

    for (auto it : ans)
    {
        cout << it << " ";
    }
}