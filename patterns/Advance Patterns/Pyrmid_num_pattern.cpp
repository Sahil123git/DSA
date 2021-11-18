#include <iostream>
using namespace std;
int main()
{
    int row;
    int counter_1, counter_2, count = 0;
    cin >> row;
    for (counter_1 = 1; counter_1 <= row; counter_1++)
    {
        for (counter_2 = 1; counter_2 <= (row - counter_1); counter_2++)
        {
            cout << "  ";
        }
        for (counter_2 = 1; counter_2 <= (counter_1 + count); counter_2++)
        {
            cout << counter_2 << " ";
        }
        count = counter_1;
        cout << endl;
    }
    return 0;
}