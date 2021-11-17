#include <bits/stdc++.h>
using namespace std;
int main()
{
    //prev_permutation T.C is O[n]
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    reverse(str.begin(), str.end());
    do //total there will be n! combinations
    {
        cout << str << endl; //factorial of str.length permutation it will give

    } while (prev_permutation(str.begin(), str.end())); //this next_perm return in bool
    return 0;
}