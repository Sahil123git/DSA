#include <iostream>
#include <set>
using namespace std;
void print(set<int> st) //this is how we print set
{
    for (int it : st)
    {
        cout << it << " ";
    }
    cout << endl;
}
int main()
{
    set<int> st;
    st.insert(2);
    st.emplace(2);
    st.emplace(3);
    st.emplace(4);
    st.emplace(5);
    st.emplace(1);
    st.emplace(6);

    // st.find(2);
    st.erase(2); //it will remove all 2               METHOD 1
    print(st);

    st.erase(st.begin()); //it will 1st ele in set    METHOD 2
    print(st);

    st.emplace(7);
    st.emplace(8);

    set<int>::iterator it1 = st.begin(); //for removing set of ele of our choice
    set<int>::iterator it2 = --st.end();
    it1++;
    it2--;
    it2--;
    print(st);
    st.erase(it1, it2); //                              MRETHOD 3
    print(st);

    auto it = st.find(7);
    if (it != st.end())
    {
        st.erase(it, st.end()); //                           METHOD 4
        print(st);
    }
    else
    {
        cout << "Not found" << endl;
    }

    st.clear();
    cout << "size is " << st.size();
    return 0;
}