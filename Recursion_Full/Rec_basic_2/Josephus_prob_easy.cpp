#include <iostream>
#include <vector>
using namespace std;
void josp(vector<int> vt, int k, int ind, int &ans)
{
    if (vt.size() == 1)
    {
        ans = vt[0];
        return;
    }
    ind = ((ind + k) % vt.size()-1);
    vt.erase(vt.begin() + ind);
    josp(vt, k, ind, ans);
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    int ans = -1;
    josp(v, k - 1, 0, ans);
    cout << ans;
}