#include <iostream>
using namespace std;
int main()
{
    int row, count;
    cin >> row;
    count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < ((row + 1) - count); j++)
        {
            cout << "1";
        }
        count = count + 2;
        for (int j = 0; j <= i; j++)
        {
            if (i == (row - 1) && (j == (row - 1)))
            {
                continue;
            }
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}