#include <iostream> //this is subsequence so we can use diff ele but must be of inc address
using namespace std;
void sub_gen(char in[], char out[], int i, int j)
{
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    out[j] = in[i];
    sub_gen(in, out, i + 1, j + 1);
    sub_gen(in, out, i + 1, j);
}
int main()
{
    char in[] = "aab";
    char out[10];
    sub_gen(in, out, 0, 0);
    return 0;
}