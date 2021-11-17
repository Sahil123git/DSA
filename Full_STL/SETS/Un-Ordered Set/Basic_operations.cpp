#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    unordered_set<int> st; //Every ele is unique but present in any order
    st.insert(1);          //O[1] avg but worst O[n]
    st.emplace(2);         //All operation are same only there is change in Time Complexity
    st.insert(3);
    st.insert(3);
    st.insert(4);

    auto it = st.find(2); //O[1]
    if (it != st.end())
    {
        cout << "found " << *(st.find(2)) << endl;
        st.erase(it);
    }
    else
    {
        cout << "Not found" << endl;
    }

    if (st.count(3)) //If ele is present it will return 1 or 0
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    for (auto it : st)
    {
        cout << it << " ";
    }
}
