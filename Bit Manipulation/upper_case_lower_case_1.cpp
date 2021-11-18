#include <iostream>
using namespace std;

void dec_to_bin(int n)
{
    for (int i = 10; i >= 0; i--)
    {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}

int main()
{
    cout << "Binary of uppercase letters" << endl;
    for (char ch = 'A'; ch <= 'D'; ch++)
    {
        dec_to_bin(char(ch));
    }
    cout << endl //here we can see there is diff in only 5th bit
         << "Binary of lowercase letters" << endl;
    for (char ch = 'a'; ch <= 'd'; ch++)
    {
        dec_to_bin(char(ch));
    }
    cout << endl;
    //upper case to lower case
    char upper_c = 'A';
    int i = (1 << 5);
    cout << char(upper_c | i) << " ";

    //lower case to upper case
    char lower_c = 'a';
    i = (1 << 5);
    i = ~(i);
    cout << char(i & lower_c) << endl;

    //shortcut for lower case and upper case
    char lower_cc = 'a', upper_cc = 'A';
    dec_to_bin(' ');
    dec_to_bin('_');

    cout << char(lower_cc & '_') << " " << char(upper_cc | ' ');
    return 0;
}