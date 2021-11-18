#include <iostream>
using namespace std;
int main()
{
    int savings;
    scanf("%d", &savings);
    if (savings > 5000)
    {
        if (savings < 10000)
        {
            cout << "shopping";
        }
        else
        {
            cout << "Road trip";
        }
    }
    else if (savings > 2000)
    {
        cout << "best friends";
    }
    else
    {
        cout << "friends";
    }
    return 0;
}