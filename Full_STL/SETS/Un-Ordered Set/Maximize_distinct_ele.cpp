#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
void unique_ele_any_order(vector<int> v, int k)
{
    unordered_set<int> st;
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        st.insert(v[i]);
    }
    int d_size = st.size();
    k = size / k;   //it will make the group of req subset
    if (d_size > k) //if size of distinct ele is greater than k, then k will be the output
    {
        cout << k;
    }
    else //else print the number of distinct ele
    {
        cout << d_size;
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
    int k;
    cin >> k;
    unique_ele_any_order(v, k);
    return 0;
}