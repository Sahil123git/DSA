#include <iostream>
#include <vector>
using namespace std;
vector<int> filter_num(vector<int> &v, int i)
{
    vector<int> ans_i; //here the last bit is pointing to the first address of vectors v
    int j = 0;
    while (i > 0)
    {
        if (i & 1)
        {
            ans_i.push_back(v[j]);
        }
        i = i >> 1;
        j++;
    }
    return ans_i;
}
vector<vector<int>> subset_gen(vector<int> &v)
{
    int sz = v.size();
    vector<vector<int>> ans;
    for (int i = 0; i < (1 << sz); i++) //here less than (1<<sz) means if it is 8 it will work till 7
    {
        vector<int> fltd_num = filter_num(v, i);
        ans.push_back(fltd_num);
    }
    return ans;
}
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
    vector<vector<int>> ans = subset_gen(v);
    // cout << ans.size();
    // cout << ans[0].size();

    for (auto it : ans)
    {
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
    return 0;
}