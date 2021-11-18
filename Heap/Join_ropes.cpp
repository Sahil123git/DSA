#include <iostream>
#include <queue>
using namespace std;
long long minCost(long long arr[], long long n)
{
    // Your code here
    priority_queue<long, vector<long>, greater<long>> pq(arr, arr + n);
    long long total_cost = 0;
    while (pq.size() > 1)
    {
        long long ele1 = pq.top();
        pq.pop();

        long long ele2 = pq.top();
        pq.pop();

        long long sum_2_ropes = ele1 + ele2;
        total_cost += sum_2_ropes;
        pq.push(sum_2_ropes);
    }
    return total_cost;
}
int main()
{
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minCost(arr, n);
}