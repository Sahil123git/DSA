#include <iostream>
using namespace std;
int main()
{
    int i = 0, c, b = 0;
    c = i++ - --i + ++i - i++;
    cout << i << " " << c << endl;
    b = b++ - --b + ++b - b++; //while b value is not 0 it's 2
    cout << b << endl;
    return 0;
}
