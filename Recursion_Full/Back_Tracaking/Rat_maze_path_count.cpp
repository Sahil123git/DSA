#include <iostream>
using namespace std;
int rat_in_maze(char maze[10][10], int soln[][10], int i, int j, int m, int n, int path)
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
        return path + 1;
    }

    if (i > m || j > n)
    {
        return 0;
    }

    if (maze[i][j] == 'X')
    {
        return 0;
    }
    // cout << soln[i][j] << " " << i << " " << j << endl;
    soln[i][j] = 1;
    int right_move = rat_in_maze(maze, soln, i, j + 1, m, n, path);
    int down_move = rat_in_maze(maze, soln, i + 1, j, m, n, path);
    soln[i][j] = 0;

    if (right_move || down_move)
    {
        return (path + right_move + down_move);
    }
    return path;
}
int main()
{
    char maze[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0X00",
    };
    int soln[10][10] = {0};
    int n, m;
    n = m = 4;
    int path = 0;
    int ans = rat_in_maze(maze, soln, 0, 0, m - 1, n - 1, path);

    if (ans == 0)
    {
        cout << "path doesn't exist" << endl;
    }
    cout << ans;
    return 0;
}
