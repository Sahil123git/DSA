#include <iostream>
using namespace std;
int main()
{
    int coloumn;
    int counter_1, counter_2, count = 1;
    cin >> coloumn;
    for (counter_1 = 1; counter_1 <= 3; counter_1++)
    {
        for (counter_2 = 1; counter_2 <= coloumn; counter_2++)
        {
            if ((counter_1 + counter_2) % 4 == 0 || (counter_1 == 2) && (counter_2 % 2 == 0))
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }

        cout << endl;
    }
    return 0;
}