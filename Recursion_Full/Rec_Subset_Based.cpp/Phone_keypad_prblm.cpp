#include <iostream>
using namespace std;
char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void gen_names(char *in, char *out, int i, int j)
{
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    int digit = in[i] - '0'; //to extract the numbers from the char arr
    if (digit == 1 || digit == 0)
    {
        gen_names(in, out, i + 1, j); //because it is 0 and 1 index arr is having null
    }

    for (int k = 0; keypad[digit][k] != '\0'; k++)
    {
        out[j] = keypad[digit][k];
        gen_names(in, out, i + 1, j + 1);
    }
    return;
}

int main()
{
    char in[1000];
    cin >> in;
    // in[0] = '2';
    // in[1] = '3';
    // in[2] = '\0';
    // char in[1000] = {'2', '3'};
    char out[1000];
    gen_names(in, out, 0, 0);
    return 0;
}