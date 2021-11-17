#include <iostream>
using namespace std;

bool is_solve(int board[][10], int i, int j, int n)
{
    for (int row = 0; row < i; row++) //here we are checking vertically
    {
        if (board[row][j] == 1)
        {
            return false;
        }
    }

    int x = i;
    int y = j;
    while (x >= 0 && y >= 0) //checking left diagonal
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
    while (x >= 0 && y < n) //checking right diagonal
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

bool N_queen(int board[][10], int i, int n)
{
    if (i == n) //base case
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
        cout << endl
             << endl;
        return false; //modification for all occurances
    }
    for (int j = 0; j < n; j++)
    {
        if (is_solve(board, i, j, n))
        {
            board[i][j] = 1;
            bool chcking = N_queen(board, i + 1, n);
            if (chcking)
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
    N_queen(board, 0, n);
    return 0;
}