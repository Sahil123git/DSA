#include <bits/stdc++.h>
using namespace std;
string int_to_str(int num)
{
    string str;
    stringstream ss;
    ss << num;
    ss >> str;

    return str;
}
bool cmp(string st1, string st2)
{
    if (st1.size() == st2.size())
    {
        return (st1 < st2); //for this it will not swap becasue for true inbuilt not swap
    }
    else
    {
        return (st1.size() < st2.size());
    }
}
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
    vector<string> st;
    for (int i = 0; i < n; i++)
    {
        string num = int_to_str(v[i]);
        st.push_back(num);
    }
    sort(st.begin(), st.end(), cmp);
    for (auto it : st)
    {
        cout << it << " ";
    }
}