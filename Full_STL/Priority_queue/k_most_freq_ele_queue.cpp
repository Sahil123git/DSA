#include <iostream>
#include <queue>
#include <unordered_map>
// #include <vector>
// #include <utility>
#include <algorithm>
using namespace std;
class mycmp
{
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.second == p2.second)
        {
            return p1.first > p2.first; //here signs are little diff because it works like heap DS
        }                               //here top of heap tree will be greatest
        return p1.second < p2.second;
    }
};
void find_freq(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycmp> q{m.begin(), m.end()};
    //In this we are using queue pair so greater int can't fix this so use comparator
    for (int i = 0; i < k; i++)
    {
        cout << q.top().first << " ";
        q.pop();
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    find_freq(arr, n, k);
}
