#include <iostream> //for ref https://youtu.be/3pvZhwp0U9w?t=484
#include <algorithm>
#include <vector>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first) //here inbuilt function says that if u want to swap
    {                       //then return false and if not then return true
        return (a.first < b.first);
    } //like this it will not swap if a is lesser than b
    else
    {
        return (a.second > b.second);
    } //if a is greter than b then it will not swap which will make it in descending order
}
int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), comp);

    for (int i = 0; i < n; i++)
    {
        cout << a[i].first << " " << a[i].second << endl;
    }
    return 0;
}