#include <iostream>
using namespace std;
int main()
{
    int i, j;
    int row, coloumn;
    cin >> row >> coloumn;
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= coloumn; j++)
        {
            if (j >= (coloumn + 1) - i && j <= coloumn)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}