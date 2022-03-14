#include <bits/stdc++.h>
using namespace std;

// Function to print all sub strings
void subString(string s, int n)
{
    // outer loop will inc
    // inner loop will dec for every inc outer loop
    for (int i = 0; i < n; i++)
        for (int len = n; len > i; len--)
            cout << s.substr(i, len) << endl;
}

// Driver program to test above function
int main()
{
    string s = "abcd";  //T.C : O(N^3)
    subString(s, s.length());
    return 0;
}
