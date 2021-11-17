#include <iostream>
using namespace std;
void bracket_gen(char out[], int n, int ind, int open_br, int close_br)
{
    if (ind == 2 * n)
    {
        out[ind] = '\0';
        cout << out << endl;
        return;
    }
    if (open_br < n) //because there will be half open brackets
    {
        out[ind] = '(';
        bracket_gen(out, n, ind + 1, open_br + 1, close_br);
    }
    if (close_br < open_br)
    {
        out[ind] = ')';
        bracket_gen(out, n, ind + 1, open_br, close_br + 1);
    }
}
int main()
{
    int n = 2;
    cin >> n;

    char out[1000];
    int ind, open, close;
    ind = open = close = 0;
    bracket_gen(out, n, ind, open, close);
    return 0;
}