class Solution
{
public:
    int findDfs(vector<vector<int>> &vstd, vector<vector<int>> &grid, int i, int j)
    {
        int n = grid.size(), m = grid[0].size();

        int dy[4] = {0, 1, 0, -1};
        int dx[4] = {1, 0, -1, 0};

        int collect = grid[i][j];
        for (int ii = 0; ii < 4; ii++)
        {
            int indi = i + dy[ii], indj = j + dx[ii];

            if (indi >= 0 && indi < n && indj < m && indj >= 0 && vstd[indi][indj] == 0 && grid[indi][indj] > 0)
            {
                vstd[indi][indj] = 1;
                collect += findDfs(vstd, grid, indi, indj);
            }
        }

        return collect;
    }

    int findMaxFish(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vstd(n, vector<int>(m, 0));
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vstd[i][j] == 0 && grid[i][j] > 0)
                {
                    vstd[i][j] = 1;

                    res = max(res, findDfs(vstd, grid, i, j));
                }
            }
        }

        return res;
    }
};