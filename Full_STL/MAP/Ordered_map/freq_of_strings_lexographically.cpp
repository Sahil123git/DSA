#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<string, int> m;
    while (n--)
    {
        string st;
        cin >> st;

        m[st] += 1; //this is inserting and adding freq values
    }
    for (auto it : m)
    {
        cout << it.first << " " << it.second << " | ";
    }
    cout << endl;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " " << (*it).second << " | ";
    }
    return 0;
}