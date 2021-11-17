#include <iostream>
// #include <vector>
#include <set>
using namespace std;

int main() //insert ele in sorted order in ascending and store only unique ele
{
    set<int> st;
    st.insert(1); //O[log n] TC
    st.emplace(5);
    int n;
    cin >> n;
    while (n--)
    {
        int ele;
        cin >> ele;
        st.insert(ele);
    }
    auto it = st.upper_bound(1);
    if (it != st.end())
    {                                          //if ele is present it will give iterator to next ele
        cout << "upperbound  " << *it << endl; //if not present it will give iterator to next greater ele
    }                                          //if greater is also not present then it will return end()

    auto it_ = st.lower_bound(1);
    if (it != st.end())
    {                                           //if ele is present it will give iterator to that ele
        cout << "lowerbound  " << *it_ << endl; //if not present it will give iterator to next greater ele
    }                                           //if greater is also not present then it will return end()
}
