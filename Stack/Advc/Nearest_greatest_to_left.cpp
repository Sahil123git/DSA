#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    vector<int> ans;
    stack<int> st;
    for (int i = 0; i < n; i++) //1 3 2 4
    {
        if (st.size() == 0)
        {
            ans.push_back(-1);
        }
        else if (st.size() > 0 && v[i] < st.top())
        {
            ans.push_back(st.top());
        }
        else if (st.size() > 0 && v[i] >= st.top())
        {
            while (st.size() > 0 && v[i] >= st.top())
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top());
            }
        }
        st.push(v[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}