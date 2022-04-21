#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    map<string, int> mp;

    // INSERTION IN MAP----------------------------------------------
    mp.insert(make_pair("mohan", 16));

    pair<string, int> pr;
    pr.first = "raju";
    pr.second = 420;
    mp.insert(pr);

    mp["sahil"] = 12;
    mp["raj"] = 17;
    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }

    // SEARCHING IN MAP-----------------------------------------------
    string str;
    str = "sahil";
    map<string, int>::iterator it = mp.find(str);
    if (it != mp.end())
    {
        cout << "found " << mp[str] << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    cout << mp.count(str) << endl;

    // DELETION----------------------------------------------
    mp.erase(str);
    cout << mp.count(str) << endl;

    // ITERATION----------------------------------------------
    cout << "Elements in the map are :" << endl;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << (*it).first << " " << it->second << endl;
    }

    // Vector of pair implementation-----------------------------------------
    //  vector<pair<string, int>> vc;
    //  vc.push_back(pr);
    //  for (int i = 0; i < vc.size(); i++)
    //  {
    //      cout << vc[i].first << " " << vc[i].second;
    //  }
}