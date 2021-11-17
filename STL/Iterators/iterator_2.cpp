#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 9};
    vector<int>::iterator it = v.begin();

    cout << (*it) << " ";
    it = next(it);
    cout << (*it) << " ";

    it = next(it, 2); //this next will return value
    cout << (*it) << " ";
    //6:03 diff b/w advance and next
    advance(it, 3); //but this will take this it to 3 steps forward
    cout << (*it) << " ";

    it = prev(it);
    cout << (*it) << " ";

    return 0;
}