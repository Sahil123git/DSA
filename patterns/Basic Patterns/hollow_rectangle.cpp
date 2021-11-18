#include <iostream>
using namespace std;
int main()
{
    int counter1, counter2;
    int row, coloumn;
    cin >> row >> coloumn;
    for (counter1 = 1; counter1 <= coloumn; counter1++)
    {
        for (counter2 = 1; counter2 <= row; counter2++)
        {
            if (counter1 == 1 || counter1 == coloumn || counter2 == 1 || counter2 == row)
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
