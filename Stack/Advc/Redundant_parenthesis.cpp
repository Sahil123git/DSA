#include <iostream> //https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/26075966#overview
#include <stack>
using namespace std;
bool Redundant_paren(string str) //(ab+(a*c) this is also true as loop will terminate after this
{                                //-> a*c) as the size of the string ends
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ')')
        {
            // cout << str[i];
            s.push(str[i]);
        }
        else
        {
            bool redun = false;
            while (!s.empty() && s.top() != '(')
            {
                if (s.top() == '+' || s.top() == '-' || s.top() == '/' || s.top() == '*')
                {
                    // cout << "yes";
                    redun = true;
                }
                s.pop();
            }
            s.pop();
            if (redun == false)
            {
                return true; //this means there is reduncy in the expression
            }
        }
    }
    return false; //means no reduncy in the expression
}
int main()
{
    string str;
    cin >> str;

    if (!Redundant_paren(str))
    {
        cout << "No Redundancy ";
    }
    else
    {
        cout << "there is Redundancy";
    }
    return 0;
}
