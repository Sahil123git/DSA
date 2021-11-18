#include <iostream>
using namespace std;
int main()
{
    float Num1, Num2;
    char var;
    cin >> Num1 >> Num2;
    cin >> var;
    switch (var)
    {
    case '+':
        cout << Num1 + Num2;
        break;
    case '-':
        cout << Num1 - Num2;
        break;
    case '*':
        cout << Num1 * Num2;
        break;
    // case '%':
    //     cout << Num1 % Num2;  can't use float with percentagqe operator
    //     break;
    case '/':
        cout << Num1 / Num2;
        break;
    default:
        cout << "Not found ";
        break;
    }
    return 0;
}
