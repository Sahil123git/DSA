#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<pair<int, int>> v = {{1, 1}, {1, 2}};
    // v = {{2, 1}, {2, 3}, {2, 4}};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ele1, ele2;
        cin >> ele1 >> ele2;
        v.push_back({ele1, ele2});
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
}