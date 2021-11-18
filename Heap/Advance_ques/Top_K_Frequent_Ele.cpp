#include <iostream> //Leetcode:https://leetcode.com/problems/top-k-frequent-elements/
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> ump;
    for (int i = 0; i < nums.size(); i++)
    {
        ump[nums[i]] += 1;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto it : ump)
    {
        pq.push({it.second, it.first});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<int> ans;
    while (!(pq.empty()))
    {
        ans.push_back((pq.top()).second);
        pq.pop();
    }
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
    int k;
    cin >> k;

    vector<int> ans;
    ans = topKFrequent(arr, k);

    for (auto it : ans)
    {
        cout << it << " ";
    }
}