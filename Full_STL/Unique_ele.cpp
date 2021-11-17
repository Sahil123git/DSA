#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
void unique_ele_any_order(vector<int> v)
{
    unordered_set<int> st;
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        st.insert(v[i]);
    }
    for (int it : st)
    {
        cout << it << " ";
    }
    cout << endl;
}
void unique_ele_ordered(vector<int> v)
{
    unordered_set<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        auto it = st.find(v[i]);
        if (it == st.end())
        {
            cout << v[i] << " ";
            st.insert(v[i]);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    while (n--)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    unique_ele_any_order(v);
    unique_ele_ordered(v);
    return 0;
}