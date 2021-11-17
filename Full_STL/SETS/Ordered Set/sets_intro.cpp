#include <iostream>
#include <vector>
#include <set>
using namespace std;
void print(set<int> st) //this is how we print set
{
    for (int it : st)
    {
        cout << it << " ";
    }
    cout << endl;
    for (auto it = st.begin(); it != st.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main() //insert ele in sorted order in ascending and store only unique ele
{
    set<int> st;
    st.insert(1); //O[log n] Time comp
    st.emplace(2);
    int n;
    cin >> n;
    while (n--)
    {
        int ele;
        cin >> ele;
        st.insert(ele);
    }
    set<int>::iterator it = st.find(20); //O[log n] TC
    if (it != st.end())                  //let to print only if that ele is present
    {
        cout << (*it) << endl;
    }
    else
    {
        cout << "not present" << endl;
    }

    print(st);

    cout << "removal using erase" << endl;
    st.erase(st.find(2));
    print(st);
}
