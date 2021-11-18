#include <iostream>
#include <stack>
using namespace std;
bool check_parenthesis(string str)
{
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (s.empty() || s.top() != '(')
            {
                return 0;
            }
            s.pop();
        }
    }
    if (s.empty())
    {
        return 1;
    }

    return 0;
}
int main()
{
    string str = "(s(()a))";
    if (check_parenthesis(str))
    {
        cout << "string is correct";
    }
    else
    {
        cout << "string is not correct";
    }
    return 0;
}