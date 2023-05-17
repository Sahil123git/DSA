class Solution
{
public:
    void callDFS(vector<vector<char>> &grid, int i, int j)
    {
        int dy[4] = {0, 1, 0, -1};
        int dx[4] = {1, 0, -1, 0};

        for (int ii = 0; ii < 4; ii++)
        {
            int yy = i + dy[ii], xx = j + dx[ii];

            if (yy >= 0 && yy < grid.size() && xx >= 0 && xx < grid[0].size() && grid[yy][xx] == '1')
            {
                grid[yy][xx] = '0';
                callDFS(grid, yy, xx);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int cnt = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    grid[i][j] = '0';
                    callDFS(grid, i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};