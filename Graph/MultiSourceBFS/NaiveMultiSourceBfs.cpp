#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// We have to find shortest dist from every node to that block which is having ele as 1
// Here all blocks with one as ele can be treated as source
// So use multisource bfs to find shortest dist to all other nodes

int main()
{
    int n, m;
    cin >> n >> m;

    int arr[n][m], dist[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            dist[i][j] = INT_MAX; // initially dist to block which is having ele as 1 is infinity from non 1 block
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j]) // if this block is having 1 as ele then find shortest dist from this block to all other blocks
            {
                for (int ii = 0; ii < n; ii++)
                {
                    for (int jj = 0; jj < m; jj++)
                    {
                        dist[ii][jj] = min((abs(i - ii) + abs(j - jj)), dist[ii][jj]);
                    }
                }
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