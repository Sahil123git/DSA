#include <iostream>
#include <set>
using namespace std;
int main()
{
    multiset<int> mul;
    mul.insert(1);
    mul.insert(2);
    mul.insert(2);
    // mul.insert(3);
    mul.insert(4);

    cout << *(mul.lower_bound(2)) << " "; //it will give the address of that gvn num
    cout << *(mul.upper_bound(2));        //it will give the address of that number which is
                                          // greater than the gvn number
    cout << endl;
    pair<multiset<int>::iterator, multiset<int>::iterator> it = mul.equal_range(2); //this is also same as lower bound and upper bound
    cout << (*it.first) << " " << (*it.second);
    return 0;
}