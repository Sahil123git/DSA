// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //--------------------------------------------------------------------------------
    // Function to detect cycle in an undirected graph using DFS
    bool detect_cycle(int st, vector<int> adj[], bool vstd[], int par)
    {
        vstd[st] = 1;
        for (auto it : adj[st])
        {
            if (!vstd[it])
            {
                if (detect_cycle(it, adj, vstd, st))
                {
                    return 1;
                }
            }
            else if (it != par) // visited but not parent of this node
            {
                return 1;
            }
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        bool visitd[V + 1] = {0};
        // cout<<visitd[V];
        for (int i = 0; i < V; i++)
        {
            if (visitd[i] == 0 && detect_cycle(i, adj, visitd, -1))
            {
                return 1;
            }
        }
        return 0;
    }
    //-------------------------------------------------------------------------------
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends