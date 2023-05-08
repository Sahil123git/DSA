#include <bits/stdc++.h>
using namespace std;
int row[] = {0, 0, -1, 0, 1};
int col[] = {0, -1, 0, 1, 0};
int cntUntil(char keypad[][3], int i, int j, int n)
{
    if (keypad == NULL || n <= 0)
    {

        return 0;
    }

    if (n == 1)
    {

        return 1;
    }

    int move = 0, rw = 0, cw = 0, ttcount = 0;

    for (move = 0; move < 5; move++)
    {
        rw = i + row[move];
        cw = j + col[move];
        if (rw >= 0 && rw <= 3 && cw >= 0 && cw <= 2 &&
            keypad[rw][cw] != '*' && keypad[rw][cw] != '#')
        {
            ttcount += cntUntil(keypad, rw, cw, n - 1);
        }
    }

    return ttcount;
}

int cnt(char key[][3], int n)
{

    if (key == NULL || n <= 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 10;
    }

    int i = 0, j = 0, ttcount = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {

            if (key[i][j] != '*' && key[i][j] != '#')
            {
                ttcount += cntUntil(key, i, j, n);
            }
        }
    }
    return ttcount;
}

int main()
{
    char key[4][3] = {{'1', '2', '3'},
                         {'4', '5', '6'},
                         {'7', '8', '9'},
                         {'*', '0', '#'}};
    int a;
    cin >> a;
    if (a > 5 || a < 1)
    {
        cout << "Invalid Input" << endl;
    }
    else
    {
        cout << cnt(key, a) << endl;
    }

    return 0;
}