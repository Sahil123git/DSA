/*gvn 2 array start time and end time of activity
[0, 10, 15, 20, 25]
[5, 15, 30, 40, 45]
find the max productivity of a worker

1. we have chosen an activity starting at t1 time and finishing at t2
2. pick an activity whose start time does not lie between t1(inclusive) and t2(exclusive)[t1, t2) and finish time of the new activity <= than t1 or start time of the new activity >= t2 of prev activity

check every pair

start time [0, 4, 15, 20, 25]
end time [5, 15, 30, 40, 45]

eg
[15, 17] we can pick (17, 19)
[17, 19]

Brute Force
start from one act and chk all activity which does not lie b/w the range
or Recursive approach

Optimized
sort the arr acc to end time so that i can choose an activity that finish earliest */
#include <bits/stdc++.h>
using namespace std;
struct activity
{
    int stTime, endTime, number;
};

bool cmp(activity a, activity b)
{
    // if (a.endTime < b.endTime) // if activity is smaller then no need to swap
    // {
    //     return true;
    // }
    // return false;
    return a.endTime < b.endTime; //no swap if a.endTime is smaller
}
int main() // SC:O(n), TC:O(n logn)
{
    vector<int> st = {0, 10, 15, 25, 20};
    vector<int> end = {5, 15, 30, 40, 45};
    vector<int> v;
    int n = st.size();

    activity nums[n]; // array of struct

    for (int i = 0; i < n; i++)//setting startTime, endTime, number for every structure
    {
        nums[i].stTime = st[i];
        nums[i].endTime = end[i];
        nums[i].number = i;
    }

    sort(nums, nums + n, cmp);

    int finishTime = nums[0].endTime;
    int total = 1;
    v.push_back(nums[0].number);

    for (int i = 1; i < n; i++)
    {
        if (nums[i].stTime >= finishTime) // if prev finishTime <= to cur start time then only we can start other activity
        {
            total++;
            v.push_back(nums[i].number);
            finishTime = nums[i].endTime;
        }
    }

    cout << "total activites " << total << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
