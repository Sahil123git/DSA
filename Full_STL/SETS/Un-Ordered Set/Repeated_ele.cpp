#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
void Repeated_ele(vector<int> v)
{
    unordered_set<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        auto it = st.find(v[i]);
        if (it == st.end())
        {
            st.insert(v[i]);
        }
        else
        {
            cout << v[i] << " ";
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
    Repeated_ele(v);
    return 0;
}