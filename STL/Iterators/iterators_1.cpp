#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int>::iterator it = v.begin();
    cout << (*it) << " ";
    it++;
    cout << (*it) << " ";
    it = v.end();
    it--;
    cout << (*it) << " ";
    return 0;
}