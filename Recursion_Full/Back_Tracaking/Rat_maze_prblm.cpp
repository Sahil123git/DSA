#include <iostream>
using namespace std;
bool rat_in_maze(char maze[10][10], int soln[][10], int i, int j, int m, int n)
{
    if (i == m && j == n)
    {
        soln[m][n] = 1;

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << soln[i][j] << " "; //it will print the valid path
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    if (i > m || j > n)
    {
        return false;
    }

    if (maze[i][j] == 'X')
    {
        return false;
    }
    soln[i][j] = 1;
    // cout << soln[i][j] << " " << i << " " << j << endl;
    bool right_move = rat_in_maze(maze, soln, i, j + 1, m, n);
    bool down_move = rat_in_maze(maze, soln, i + 1, j, m, n);
    soln[i][j] = 0;

    if (right_move || down_move)
    {
        return 1;
    }
    return 0;
}
int main()
{
    char maze[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0X00"
    };
    int soln[10][10] = {0};
    int n, m;
    n = m = 4;

    bool ans = rat_in_maze(maze, soln, 0, 0, m - 1, n - 1);
    if (ans == false)
    {
        cout << "path doesn't exist" << endl;
    }
    return 0;
}
