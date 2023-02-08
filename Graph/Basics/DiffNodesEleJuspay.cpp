/*We have to find is there any way from source node to dest node here nodes in graph can any num
one way is to use map<int, vector<int>> adj or map every node to numbering (0 - n)
Below is the Implementation using map<int, vector<int>> adj*/
/*Test Case
 4
 2 5 7 9
 4
 2 9
 7 2
 7 9
 9 5*/

#include <bits/stdc++.h>
using namespace std;

void isConnected(map<int, vector<int>> &adj, int node, map<int, bool> &vstd) //fndng if there is way or not using DFS if dest node is vstd then means there is way
{
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (vstd[adj[node][i]] == 0)
        {
            vstd[adj[node][i]] = 1;
            isConnected(adj, adj[node][i], vstd);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    map<int, bool> vstd;
    map<int, vector<int>> adj;

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;

        vstd[ele] = 0;
    }

    int sz;
    cin >> sz;

    for (int i = 0; i < n; i++)
    {
        int src, dest;
        cin >> src >> dest;

        adj[src].push_back(dest);
    }

    for (auto it : adj) //printing adj list 
    {
        cout << it.first << "-> ";
        for (auto itt : it.second)
        {
            cout << itt << " ";
        }
        cout << endl;
    }

    int src, dest;
    cin >> src >> dest;

    vstd[src] = 1;
    isConnected(adj, src, vstd);

    if (vstd[dest]) // vstd means there is way
    {
        cout << 1;
    }
    else // means no way
    {
        cout << 0;
    }
}
