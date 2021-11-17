#include <iostream>
using namespace std;
int main()
{
    pair<int, string> p(10, "sahil");
    cout << p.first << " " << p.second << endl;

    pair<int, string> p1;
    p1 = {20, "roe"};
    cout << p1.first << " " << p1.second << endl;

    pair<int, string> p11;
    p11 = make_pair(30, "joe");
    cout << p11.first << " " << p11.second << endl;
    return 0;
}