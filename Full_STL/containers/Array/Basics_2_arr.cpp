#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 7> ar3;
    ar3.fill(10);
    for (int i = 0; i < 5; i++)
    {
        cout << ar3[i] << " ";
    }
    cout << endl;

    array<int, 5> ar5 = {0};
    array<int, 5> ar4 = {1, 2, 5, 7};
    cout << ar3.size() << " " << ar3.max_size() << " ";
    cout << ar4.front() << " " << ar4.back() << endl;
    ar5.swap(ar4);
    for (int i = 0; i < 5; i++)
    {
        cout << ar5.at(i) << " ";
    }
    cout << endl;
}