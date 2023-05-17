class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> vstd(n, vector<int>(m, -1));

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({i, j});
                    vstd[i][j] = 0;
                }
            }
        }

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int indx = q.front().first, indy = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int x = indx + dx[i], y = indy + dy[i];

                if (x < n && x >= 0 && y < m && y >= 0 && vstd[x][y] == -1)
                {
                    vstd[x][y] = vstd[indx][indy] + 1;
                    q.push({x, y});
                }
            }
        }

        return vstd;
    }
};