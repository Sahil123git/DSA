#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }

    reverse(v.begin() + 2, v.end() - 1); //our wish to add modify this reverse function
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    
    string str;
    str = "sahil dussa";
    reverse(str.begin(), str.end());
    cout << str;
    return 0;
}