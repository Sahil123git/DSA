#include <iostream>
using namespace std;

void gen_str(char num[], char out[], int i, int j)
{
    if (num[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    int dig = num[i] - '0'; //when taking 1 characters
    char ch = dig + 'A' - 1;
    out[j] = ch;
    gen_str(num, out, i + 1, j + 1);

    if (num[i + 1] != '\0') //when extracting 2 characters
    {
        int dig_2 = num[i + 1] - '0';
        int no = (dig * 10) + dig_2;
        if (no <= 26)
        {
            ch = no + 'A' - 1;
            out[j] = ch;

            
            gen_str(num, out, i + 2, j + 1);
        }
    }
    return;
}
int main()
{
    // char num[100] = {"123"};
    char num[100];
    cin >> num;
    char out[1000] = {""};

    gen_str(num, out, 0, 0);
    return 0;
}