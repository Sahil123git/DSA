#include <iostream>
using namespace std;
string check(string str)
{
    int i = 0;

    for (int j = 1; j <= str.length(); j++)
    {
        if (str[i] != str[j])
        {
            i++;
            str[i] = str[j];
        }
    }
    return str;
}
int main()
{
    string str;
    getline(cin, str);
    string new_str = check(str);
    for (int i = 0; new_str[i] != '\0'; i++)
    {
        cout << new_str[i];
    }
}