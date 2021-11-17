#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
int main()
{
    vector<pair<pair<int, int>, pair<int, int>>> v = {{{1, 2}, {3, 4}}, {{4, 2}, {5, 4}}};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second.first << " " << v[i].second.second << endl;
    }

    pair<pair<int, int>, int> vp = {{1, 2}, 3};
    cout << vp.first.first << " " << vp.first.second << " " << vp.second << endl;

    set<pair<int, int>> st;
    st.insert({1, 2});
    st.insert({2, 2});
    st.insert({3, 2});
    for (auto it : st)
    {
        cout << it.first << " " << it.second << endl;
    }

    map<pair<int, int>, string> st1;
    st1.insert({{1, 2}, "raj"});
    st1.insert({{2, 2}, "sam"});
    // st1.insert({{3, 2}, "joe"});
    st1[{1, 4}] = "ram";
    for (auto it : st1)
    {
        cout << it.first.first << " " << it.first.second << " " << it.second << endl;
    }
    for (auto it = st1.begin(); it != st1.end(); it++)
    {
        cout << (*it).first.first << " " << (*it).first.second << " " << it->second << endl;
    }
}