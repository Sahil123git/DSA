#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> near_small_left(vector<int> v, int n)
{
    vector<int> ans;
    stack<pair<int, int>> st;
    int pseudo_ind = -1;
    for (int i = 0; i < n; i++) //4 5 2 10 8
    {
        if (st.size() == 0)
        {
            ans.push_back(pseudo_ind);
        }
        else if (st.size() > 0 && v[i] > st.top().first)
        {
            ans.push_back(st.top().second);
        }
        else if (st.size() > 0 && v[i] <= st.top().first)
        {
            while (st.size() > 0 && v[i] <= st.top().first)
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                ans.push_back(pseudo_ind);
            }
            else
            {
                ans.push_back(st.top().second);
            }
        }
        st.push({v[i], i});
    }
    return ans;
}

vector<int> near_small_right(vector<int> v, int n)
{
    vector<int> ans;
    int pseudo_ind = n; //we r taking pseudo_ind as n so that we easily subtract
    stack<pair<int, int>> st;
    for (int i = n - 1; i >= 0; i--) //4 5 2 10 8
    {
        if (st.size() == 0)
        {
            ans.push_back(pseudo_ind);
        }
        else if (st.size() > 0 && v[i] > st.top().first)
        {
            ans.push_back(st.top().second);
        }
        else if (st.size() > 0 && v[i] <= st.top().first)
        {
            while (st.size() > 0 && v[i] <= st.top().first)
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                ans.push_back(n);
            }
            else
            {
                ans.push_back(st.top().second);
            }
        }
        st.push({v[i], i});
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
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
    vector<int> ans1 = near_small_left(v, n);
    vector<int> ans2 = near_small_right(v, n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << ans1[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << ans2[i] << " ";
    // }
    int width[n];
    for (int i = 0; i < n; i++)
    {
        width[i] = ans2[i] - ans1[i] - 1;
        // cout << width[i] << " ";
    }
    // cout << "s";
    int final_ans[n];
    for (int i = 0; i < n; i++)
    {
        final_ans[i] = width[i] * v[i];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << final_ans[i] << " ";
    // }
    cout << *max_element(final_ans, final_ans + n);
    return 0;
}