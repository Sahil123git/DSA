long long minCost(long long arr[], long long n)
{
    if (n == 1)
    {
        return 0;
    }

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    long long totalCost = 0;
    while (pq.size() >= 2)
    {                              // using priority queue for finding min 2 ele
        long long ele1 = pq.top(); // so tht we can combine them
        pq.pop();
        long long ele2 = pq.top();
        pq.pop();

        totalCost += (ele1 + ele2);
        pq.push(ele1 + ele2);
    }
    return totalCost;
}
// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1