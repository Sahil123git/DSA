#include <iostream> //GeeksForGeeks
#include <queue>    //O(NlogK)
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> qu_min;
    vector<int> vt;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        qu_min.push(arr[i]);
        if (qu_min.size() == k)
        {
            vt.push_back(qu_min.top());
            qu_min.pop();
            // cout<<qu_min.top()<<" ";
        }
    }

    while (!(qu_min.empty()))
    {
        vt.push_back(qu_min.top());
        qu_min.pop();
    }
    for (int i = 0; i < vt.size(); i++)
    {
        cout << vt[i] << " ";
    }
}
