#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    map<int, int> st;
    st.insert({1, 2});
    st.insert({2, 2});
    st.insert({3, 4});
    st.insert({3, 2});
    st.insert({5, 3});

    auto it3 = st.lower_bound(3); //this upper and lower bound are map functions
    auto it4 = st.upper_bound(3); //TIME COMPLEXITY O[logN] of upper and lower bound
    cout << (*it3).first << " " << it3->second << endl;
    cout << (*it4).first << " " << it4->second << endl;
}