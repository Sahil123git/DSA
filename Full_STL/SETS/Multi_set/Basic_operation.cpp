#include <iostream>
#include <set>
using namespace std;
void print(multiset<int> mul)
{
    for (int i : mul)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    multiset<int> mul;
    mul.insert(1);
    mul.insert(3);
    mul.insert(4);
    mul.insert(2);
    mul.insert(2);
    mul.insert(2);
    mul.insert(4);

    print(mul);
    mul.erase(4); //remove all instances of ele

    mul.insert(8);
    mul.insert(8);
    mul.insert(8);
    auto it = mul.find(8); //find only 1 instance of ele
    mul.erase(it);         //delete only 1 instance of ele

    print(mul);
    cout << mul.count(2);
}