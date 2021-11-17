#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    map<int, int> mp, mp2;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]] += 1;
    }

    int com_freq = 0;
    for (auto it = mp.rbegin(); it != mp.rend(); it++)
    {
        int freq = it->second;
        it->second = com_freq;
        com_freq += freq; //adding freq so that can use it for nxt ele
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    cout << mp2.size();
}