#include <iostream>
using namespace std;
int main()
{
    int row, coloumn;
    int counter_1, counter_2;
    cin >> row >> coloumn;
    for (counter_1 = 1; counter_1 <= row; counter_1++)
    {
        for (counter_2 = 1; counter_2 <= coloumn; counter_2++)
        {
            if (counter_2 >= 1 && counter_2 <= (coloumn + 1) - counter_1)
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
    return 0;
}