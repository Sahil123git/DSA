#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(3);
    st.insert(4);

    auto it1 = lower_bound(st.begin(), st.end(), 3); //these are not set functio so they are
    auto it2 = upper_bound(st.begin(), st.end(), 3); //O[N]
    cout << *it1 << " " << *it2 << endl;

    auto it3 = st.lower_bound(3); //this upper and lower bound are set functions
    auto it4 = st.upper_bound(3); //TIME COMPLEXITY O[logN] of upper and lower bound
    cout << *it3 << " " << *it4 << endl;
}