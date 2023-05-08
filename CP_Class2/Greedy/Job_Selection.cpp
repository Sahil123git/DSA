/*
JobIds  DeadLine   Profit
0            5         30
1            2         100
2            2         50
3            1         75
4            3         49

total = 100 + 75 + 49 + 30
[1, 1, 1, 0, 1]*/
#include <bits/stdc++.h>
using namespace std;

struct jobs
{
    int jobId, deadline, profit;
};

bool mycmp(jobs a, jobs b)
{
    return a.profit > b.profit;
}

int main() // TC: O(n^2) SC:O(n)
{
    int deadLIne[] = {5, 2, 2, 1, 3};
    int profit[] = {30, 100, 50, 75, 49};

    int n = sizeof(deadLIne) / sizeof(deadLIne[0]);
    jobs nums[n];
    int jobsq[n];

    for (int i = 0; i < n; i++)
    {
        jobsq[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        nums[i].jobId = i;
        nums[i].deadLIne = deadLIne[i];
        nums[i].profit = profit[i];
    }
    sort(nums, nums + n, mycmp); // sorting acc to max profit
    
    for (int i = 0; i < n; i++)  // do that job first whose profit is more
    // let's say if any job is having deadline 1 then give this time to highest profit job
    {
        jobs pickedJob = nums[i];
        for (int j = min(n, pickedJob.deadline) - 1; i >= 0; j--)
        {
            if (jobsq[j] == -1)
            {
                jobsq[j] = pickedJob.jobId;
                total = total + pickedJob.profit;
                break;
            }
        }
    }

    cout << total << endl;
    for (int i = 0; i < n; i++)
    {
        if (Jobsq[i] != -1)
        {
            cout << "At time : " << i << " do job with : " << jobsq[i] << endl;
        }
    }
}