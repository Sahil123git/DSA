#include <iostream>
using namespace std;
int main()
{
    int n, i, j;
    cin >> n;
    for (i = 1; i <= n; i++) //For Upper triangle
    {
        for (j = 1; j <= i; j++)
        {
            cout << "*"; //first this will print
        }
        int space = 2 * n - 2 * i;
        for (j = 1; j <= space; j++)
        {
            cout << " "; //Second this will print req spaces in that row
        }
        for (j = 1; j <= i; j++)
        {
            cout << "*"; //Third this will print
        }
        cout << endl;
    }
    for (i = n; i >= 1; i--) //For Lower triangle
    {
        for (j = 1; j <= i; j++)
        {
            cout << "*"; //first this will print
        }
        int space = 2 * n - 2 * i;
        for (j = 1; j <= space; j++)
        {
            cout << " "; //Second this will print req spaces in that row
        }
        for (j = 1; j <= i; j++)
        {
            cout << "*"; //Third this will print
        }
        cout << endl;
    }
    return 0;
}