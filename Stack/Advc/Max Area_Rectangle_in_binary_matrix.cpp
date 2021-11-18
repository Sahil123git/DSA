#include <iostream> //https://www.youtube.com/watch?v=St0Jf_VmG_g&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=8
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> near_small_left(vector<int> v, int n) //NSL2
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

vector<int> near_small_right(vector<int> v, int n) //NSR
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
int max_area(vector<int> v) //Maxi area histogram code
{
    int n = v.size();
    vector<int> ans1 = near_small_left(v, n);
    vector<int> ans2 = near_small_right(v, n);

    int width[n];
    for (int i = 0; i < n; i++)
    {
        width[i] = ans2[i] - ans1[i] - 1;
    }
    int final_ans[n];
    for (int i = 0; i < n; i++)
    {
        final_ans[i] = width[i] * v[i];
    }

    return *max_element(final_ans, final_ans + n);
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<int> v;
    for (int j = 0; j < n; j++)
    {
        v.push_back(arr[0][j]); //we took this diff because it don't need extra
    }                           //conditions
    int maxi = max_area(v);     //this maxi is for 1st row only
    cout << maxi << endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                v[j] = 0; // this will make that vector index 0 which is having 0 element
                // cout<<"Fd ";
            }
            else
            {
                // cout << "no";
                v[j] += arr[i][j]; //this will add the current address vector ele to the prev running vector
            }
        }
        cout << max_area(v) << " " << i << " | ";
        maxi = max(maxi, max_area(v)); //this will find the max rect area
    }
    cout << endl;
    cout << maxi;
}