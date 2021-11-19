#include <iostream>
#include <vector>
using namespace std;
int peakIndexInMountainArray(vector<int> &arr)
{
    int len = arr.size();
    int low = 0, high = len - 1, mid;
    while (low != high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid + 1])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
            // cout<<low<<" "<<high;
        }
    }
    // cout << endl
    //      << mid << " " << arr[low];
    return arr[low];
}
int main()
{
    int n;
    cin >> n;
    vector<int> vt;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        vt.push_back(ele);
    }
    cout << peakIndexInMountainArray(vt);
}