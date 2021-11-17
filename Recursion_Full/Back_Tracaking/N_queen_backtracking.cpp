#include <iostream>
using namespace std;
bool is_safe(int board[][10], int i, int j, int n)
{
    for (int row = 0; row < i; row++) //checking vertically
    {
        if (board[row][j] == 1)
        {
            return false;
        }
    }

    int x = i;
    int y = j;
    while (x >= 0 && y >= 0) //checking left diagonally
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }

    x = i;
    y = j;
    while (x >= 0 && y < n) //checking right diagonally
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y++;
    }
    return true;
}

bool solve_N_queen(int board[][10], int n, int i)
{
    if (i == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j])
                {
                    cout << "Q ";
                }
                else
                {
                    cout << "_ ";
                }
            }
            cout << endl;
        }
        return true;
    }

    for (int j = 0; j < n; j++)
    {
        if (is_safe(board, i, j, n))
        {
            board[i][j] = 1;
            bool next_chkng = solve_N_queen(board, n, i + 1);
            if (next_chkng)
            {
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;

    int board[10][10] = {0};
    solve_N_queen(board, n, 0);
    // for (int i = 0; i < 4; i++)//here also arr is effected
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}