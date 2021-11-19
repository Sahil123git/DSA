#include <iostream>
#include <vector>
using namespace std;
int find_min_V_shp(vector<int> &arr)
{
    int len = arr.size();
    int low = 0, high = len - 1, mid;
    while (low != high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return arr[low]; //return any mid or high they both are same
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
    cout << find_min_V_shp(vt);
}