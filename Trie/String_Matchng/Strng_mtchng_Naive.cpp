#include <iostream>
using namespace std;
int main()
{
    string str;
    cin >> str;

    string fnd;
    cin >> fnd;

    for (int i = 0; i + fnd.size() <= str.size(); i++) // O(n.m)
    {                                                  // where n=size of str and
        if (fnd == str.substr(i, fnd.size()))          // m=size of fnd
        {
            cout << "found" << endl;
            return 0;
        }
    }
    cout << "false" << endl;
}