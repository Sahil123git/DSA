#include <iostream>
#include <vector>
using namespace std;
bool dfs_hlpr(int node, vector<int> &vstd, vector<int> adj[], int colr, int prnt)
{
    vstd[node] = colr;

    for (auto it : adj[node]) // this it is having all cntd vertices of node
    {
        if (vstd[it] == 0)
        {
            if (!dfs_hlpr(it, vstd, adj, 3 - colr, node)) // if we got 0 then it is not bipartite graph
            {
                return 0;
            }
        }
        else if (it != prnt && colr == vstd[it]) // chking if this cnctd vertex is not parent if not then chk it colr
        {
            return 0;
        }
    }
    return 1;
}
bool chk_bipartite(vector<int> adj[], int n)
{
    vector<int> vstd(n, 0);
    int colr = 1;
    bool ans = dfs_hlpr(0, vstd, adj, colr, -1);

    for (auto it : vstd)
    {
        cout << it << " ";
    }
    cout << endl;
    return ans;
}
void adj_lst(vector<int> adj[], int v1, int v2)
{
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
}
int main()
{
    int n = 3;
    vector<int> adj[n];
    adj_lst(adj, 0, 2);
    adj_lst(adj, 0, 1);
    adj_lst(adj, 2, 1); // this will make this graph not bipartite

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < adj[i].size(); j++)
    //     {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << chk_bipartite(adj, n);
    return 0;
}
