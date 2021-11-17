#include <iostream>
#include <set>
using namespace std;
void redundant_char(string str, int i, set<string> &st)
{
    if (str[i] == '\0')
    {
        st.insert(str);
        return;
    }

    for (int j = i; str[j] != '\0'; j++)
    {
        swap(str[i], str[j]);
        redundant_char(str, i + 1, st);
        swap(str[i], str[j]);
    }
}
int main()
{
    string str;
    cin >> str;

    set<string> st;
    redundant_char(str, 0, st);
    for (auto it : st)
    {
        cout << it << " ";
    }
}