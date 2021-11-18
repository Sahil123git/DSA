#include <iostream>
using namespace std;
int main()
{
    int row, coloumn;
    int counter_1, counter_2;
    cin >> row >> coloumn;
    for (counter_1 = 1; counter_1 <= row; counter_1++)
    {
        for (counter_2 = 1; counter_2 <= counter_1; counter_2++) //like this
        {
            // if (counter_2 >= 1 && counter_2 <= counter_1)      we can do w/o this also
            // {
            if ((counter_2 + counter_1) % 2 == 0)
            {
                cout << "1 "; //(i+j) -> Even  (1)
            }
            else
            {
                cout << "0 "; //(i+j) -> odd  (0)
            }
            // }
        }
        cout << endl;
    }
    return 0;
}