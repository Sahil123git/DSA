#include <iostream>
using namespace std;
void case_chng(string in_st, string out_st)
{
    if (in_st.length() == 0)
    {
        cout << out_st << endl;
        return;
    }
    string ot1 = out_st;
    string ot2 = out_st;

    ot1.push_back(in_st[0]);
    ot2.push_back(toupper(in_st[0]));

    in_st.erase(in_st.begin() + 0);

    case_chng(in_st, ot1);
    case_chng(in_st, ot2);
    return;
}
int main()
{
    string str1, str2;
    cin >> str1;
    case_chng(str1, str2);
    return 0;
}