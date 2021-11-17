#include <iostream>
using namespace std;
void chng_pi(char str[], int i)
{
    if (str[i] == '\0')
    {
        return;
    }
    if (str[i] == 'p' && str[i + 1] == 'i')
    {
        int j = i + 2; //i+2 is just after the pi
        while (str[j] != '\0')
        {
            j++; //this will take j to null character
        }
        while (i + 2 <= j)
        {
            str[j + 2] = str[j]; //this will shift every char after  2 words forward
            j--;
        }
        str[i] = '3';
        str[i + 1] = '.';
        str[i + 2] = '1';
        str[i + 3] = '4';
        chng_pi(str, i + 4); //this will point to next of 4 ele
    }
    else
    {
        chng_pi(str, i + 1);
    }
    return;
}

int main()
{
    char ch[10000];
    cin >> ch;
    chng_pi(ch, 0);

    cout << ch;
    return 0;
}