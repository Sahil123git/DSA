#include <iostream> //see video at (3:57) see example why use diff approach for directed
#include <vector>   //using undirected methd that will be cyclic graph
using namespace std;

void add_edge(vector<vector<int>> &adj, int ed1, int ed2) // adj_List
{
    adj[ed1].push_back(ed2);
}

bool dfs_chk(int st, vector<bool> &vstd, vector<bool> &stk, vector<vector<int>> &adj)
{
    vstd[st] = 1; // this is for chking whether that vertex is visited in past
    stk[st] = 1;  // we'll make 0 while going back from some vertex

    for (auto nbr : adj[st])
    {
        if (stk[nbr] == 1) // if this is that vertex which we visited in past
        {
            return 1;
        }
        else if (vstd[nbr] == 0) // if this is new not visited vertex
        {
            if (dfs_chk(nbr, vstd, stk, adj))
            {
                return 1;
            }
        }
    }
    stk[st] = 0; // if there is no cycle through this vertex
    return 0;
}
bool chk_cycle(vector<vector<int>> adj)
{
    vector<bool> vstd(adj.size(), 0);
    vector<bool> stack(adj.size(), 0);

    for (int i = 0; i < adj.size(); i++) // if there are disconnected vertecies
    {
        if (dfs_chk(i, vstd, stack, adj)) // to chk whether there is cycyle through
        {                                 // this vertex
            return 1;
        }
    }
    return 0;
}
int main()
{
    int v = 4;
    vector<vector<int>> adj(4, vector<int>());
    add_edge(adj, 0, 1);
    // add_edge(adj, 1, 2);
    add_edge(adj, 2, 1); // this is kinda self loop

    // for (int i = 0; i < adj.size(); i++)
    // {
    //     cout << i << "-->";
    //     for (int j = 0; j < adj[i].size(); j++)
    //     {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << chk_cycle(adj);
}
