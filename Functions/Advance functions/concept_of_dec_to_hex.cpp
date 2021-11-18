#include <iostream>
using namespace std;
int main()
{
    string str[2];
    int arr[2];
    int rem = 3, rem_2 = 11;
    str[0] = rem + 48;    //for both cases first value will add and then correspond to it's ascii value
    str[1] = rem_2 + 'a'; //because in (string or char) everything is in character
    arr[0] = rem + 48;
    arr[1] = rem_2 + 'a'; //(array or int) take any number or character in int form

    cout << "str => " << str[0] << " " << str[1] << endl;
    cout << "arr => " << arr[0] << " " << arr[1];

    return 0;
}