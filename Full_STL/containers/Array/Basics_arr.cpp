#include <iostream>
#include <array>
using namespace std;
array<int, 5> ar2; //declaring arr global will allocate all ele with 0
int main()
{
    array<int, 5> ar1 = {7, 2, 3};
    for (int i = 0; i < 5; i++)
    {
        cout << ar1.at(i) << " ";
    }
    cout << endl;
    cout << ar1.front() << " " << ar1.back();
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << ar2.at(i) << " ";
    }
    cout << endl;
}