#include <iostream> //remember to make 2 stacks for this type of problems
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
    stack<pair<int, int>> st; //1st int is ele and 2nd int is Addresss
    for (int i = 0; i < n; i++)
    {
        if (st.size() == 0)
        {
            ans.push_back(-1);
        }
        else if (st.size() > 0 && v[i] < st.top().first)
        {
            ans.push_back(st.top().second);
        }
        else if (st.size() > 0 && v[i] >= st.top().first)
        {
            while (st.size() > 0 && v[i] >= st.top().first)
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top().second);
            }
        }
        st.push({v[i], i});
    }

    for (int i = 0; i < n; i++)
    {
        ans[i] = i - ans[i]; //comment this to check what ans is storing
        cout << ans[i] << " ";
    }
}