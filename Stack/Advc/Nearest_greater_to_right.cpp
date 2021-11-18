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
    for (int i = n - 1; i >= 0; i--)
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
    reverse(ans.begin(), ans.end()); //because we are checking from last so we will get ans arr in rev order
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}
/*
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        stack<int> st;
        vector<int> ans;
        int n=n2.size();
        for(int i=n-1;i>=0;i--)
        {
            if(st.size()==0)
            {
               ans.push_back(-1);
            }
            else if(st.top() > n2[i])
            {
               ans.push_back(n2[i]);
            }
            else if(st.top() <= n2[i])
            { 
               while(st.size()!=0 && st.top()<=n2[i])
               {
                   st.pop();
               }
               if(st.size()==0)
               {
                   ans.push_back(-1);
               }
               else
               {
                   ans.push_back(st.top());
               }
            }
        }
        int hsh_arr[10000]
        for(int i=0;i<=n;i++)
        {
            hsh_arr[n2[i]]=v[i];
        }
        for(int i=0;i<n1.size();i++)
        {
            cout<<hsh_arr[n1[i]]<<" ";
        }
    }
};*/