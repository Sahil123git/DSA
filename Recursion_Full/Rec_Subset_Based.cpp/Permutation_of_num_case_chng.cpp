#include <iostream>
#include <vector>
using namespace std;
void case_chng(string in, string out, vector<string> &ans)
{
    if (in.length() == 0)
    {
        ans.push_back(out);
        return;
    }
    if (isalpha(in[0]))
    {
        string ot1 = out;
        string ot2 = out;

        ot1.push_back(tolower(in[0]));
        ot2.push_back(toupper(in[0]));

        in.erase(in.begin() + 0);

        case_chng(in, ot1, ans);
        case_chng(in, ot2, ans);
    }
    else
    {
        string ot = out;
        ot.push_back(in[0]);
        in.erase(in.begin() + 0);

        case_chng(in, ot, ans);
    }
}
int main()
{
    string in_s, out_s;
    cin >> in_s;
    vector<string> ans;
    case_chng(in_s, out_s, ans);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}