#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int chk = 0;
    while (n--)
    {
        int ele;
        cin >> ele;
        chk = chk ^ ele;
    }
    cout << chk << endl;
}