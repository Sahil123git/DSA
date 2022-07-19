#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
// We have to find shortest dist from every node to that block which is having ele as 1
// Here all blocks with one as ele can be treated as source
// So use multisource bfs to find shortest dist to all other nodes

int main()
{
    int n, m;
    cin >> n >> m;

    int arr[n][m], dist[n][m];
    queue<pair<int, int>> qu;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            dist[i][j] = INT_MAX; // initially dist to block which is having ele as 1 is infinity from non 1 block
            if (arr[i][j] == 1)
            {
                qu.push({i, j}); // inserting multiple source nodes in queue
                dist[i][j] = 0;
            }
        }
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1}; // to chk all 4 coordinates of a block

    // MULTI-SOURCE BFS CODE
    while (!qu.empty()) // while queue is not empty
    {
        int x = qu.front().first;  // this x and y combines is
        int y = qu.front().second; // center node whose nbr we'll chk
        qu.pop();                  // pop this chkd queue out

        for (int i = 0; i < 4; i++) // chkng all 4 coordinates
        {
            int elex = x + dx[i], eley = y + dy[i];
            if (elex < n && elex >= 0 && eley >= 0 && eley < m && dist[elex][eley] == INT_MAX) // if dist of particular ele is not INT_MAX means tht is already visited
            {
                qu.push({elex, eley});             // push these coordinates also in queue as pair
                dist[elex][eley] = 1 + dist[x][y]; // update dist of this nbrng ele
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}