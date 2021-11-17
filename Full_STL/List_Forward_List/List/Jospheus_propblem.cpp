#include <iostream>
#include <list>
using namespace std; //Time comp O[n*k]
int main()
{
    list<int> l;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        l.push_back(i);
    }
    int k;
    cin >> k;
    auto it = l.begin();
    while (l.size() > 1)
    {
        for (int count = 1; count < k; count++)
        {
            it++;
            if (it == l.end()) //so that it will come back to begin
            {
                it = l.begin();
            }
        }
        it = l.erase(it);  //return address af next ele
        if (it == l.end()) //so that it will come back to begin
        {
            it = l.begin();
        }
        // for (auto it : l)
        // {
            // cout << it << " ";
        // }
        // cout << endl;
    }
    // for (auto it : l)
    // {
    //     cout << it << " ";
    // }
    cout << *it << " " << l.size();
}