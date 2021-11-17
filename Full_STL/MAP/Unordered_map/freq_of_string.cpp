#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    unordered_map<string, int> m;
    while (n--)
    {
        string str;
        cin >> str;
        m[str] += 1;
    }
    int q;
    cin >> q;
    while (q--)
    {
        string ele;
        cin >> ele;
        cout << ele << " " << m[ele] << endl;
    }
    return 0;
}