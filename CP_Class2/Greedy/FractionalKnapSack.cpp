/*Fractional Knapsack is having cpty, every item is having weight, and value
w = 50;
wt = {10, 20, 30}
val = {50, 40, 60}

eg:
10kg = 50val
1kg = (50val / 10kg) * 1kg
1kg = 5val
 */
#include <bits/stdc++.h>
using namespace std;
struct items
{
    int wt, val, number;
};
bool cmp(items a, items b) // sorting val acc to (val per weight)
{                          // chkng all val for unit weight
    double valwtA = (double)a.val / a.wt;
    double valwtB = ((double)b.val / b.wt) * 1; // how much val it will give when it's weight is 1

    return valwtA > valwtB; // if fst one is grater then no swapping
}
double fractknapsack(int W, int wt[], int val[], int n)
{
    items nums[n]; // array of structure
    for (int i = 0; i < n; i++)
    {
        nums[i].wt = wt[i];
        nums[i].val = val[i];
        nums[i].number = i;
    }
    sort(nums, nums + n, cmp);

    double totalVal = 0.0; // initial total val
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        items picked = nums[i];
        if (picked.wt <= W)
        {
            totalVal += picked.val;
            v.push_back(picked.number);
            W -= picked.wt;
        }
        else // if item's weight is greater than left out weight then find how much val you will get when you will use left out weight
        {
            totalVal += ((double)picked.val / picked.wt) * W; // using unitary mthd
            /*gvn wgt =  gvn val
              rem wgt = (gvn val / gvn wgt) * rem wgt */
            v.push_back(picked.number);
            W = 0;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return totalVal;
}

int main() // TC:O(n logn), SC: O(n)
{
    int w = 50;
    int wt[] = {10, 20, 30};
    int val[] = {50,
                 60,
                 60};

    int n = sizeof(wt) / sizeof(wt[0]);
    // cout << n << endl;
    cout << fractknapsack(w, wt, val, n);
}