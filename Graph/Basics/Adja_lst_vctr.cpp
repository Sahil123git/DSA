#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << v << "-->";
        for (auto x : adj[v])
            cout << x << ",";
        printf("\n");
    }
}

int main()
{
    int V = 5;
    vector<int> adj[V]; // v size vectors(arr of vectors)
    // this is a arr of size V where all ele will act as vctr
    //  vector<vector<int>> vt(4, vector<int>(4, 0)); this is vector of vec
    //  vector<vector<int>> vec(3, vector<int>()); vec of vec with height as 3
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
    return 0;
}
