#include <iostream>
#include <vector>
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
    int ones = 0, twos = 0;
    for (int i = 0; i < n; i++)
    {
        ones = (ones ^ v[i]) & ~(twos);
        twos = (twos ^ v[i]) & ~(ones);
    }
    cout << ones;
}