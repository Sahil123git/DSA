#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    int maxi, mini;
    maxi = *max_element(v.begin(), v.end() - 2); //it will end at 2 index
    mini = *min_element(v.begin(), v.end());     //here it will start from index 2
    cout << maxi << " " << mini << endl;

    int sum1 = accumulate(v.begin(), v.end(), 0);     //here it will get the initial val as 0
    int sum2 = accumulate(v.begin() + 2, v.end(), 4); //now it will add 4 also to the total sum
    cout << sum1 << " " << sum2 << endl;

    // int res = 100;
    // cout << accumulate(v.begin(), v.end(), res, minus<int>);
    return 0;
}