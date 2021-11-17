#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<string> st;
    for (int i = 0; i < n; i++)
    {
        string ele;
        cin >> ele;
        st.insert(ele);
    }
    for (auto it : st)
    {
        cout << it << " ";
    }
    return 0;
}