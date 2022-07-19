// Topological Sort Concept : If (A node comes before B) in Graph, then in Topological sort also it will come before
// Concept from : https://www.youtube.com/watch?v=Zbbe9FYVnM4
// Topological Sort using DFS (Stack)
// First Insert in stack tht node which is having no out-degree(means no dependency) then rest nodes

void dfsHelper(int i, stack<int> &stk, vector<int> &vstd, vector<int> adj[])
{
    vstd[i] = 1;

    for (auto it : adj[i]) // so using this we are going to the last node, which is having no dependencies
    {
        if (vstd[it] == 0) //(means no outDegree) and then from tht we'll backtrack to prev nodes and store in stack
        {
            dfsHelper(it, stk, vstd, adj); // Cncpt is: if one node is having any child node then visit tht
        }                                  // means reach at the last child node
    }
    stk.push(i); // then in the lst insert this (Processed) node also in stack
}

vector<int> topoSort(int V, vector<int> adj[])
{
    stack<int> stk;
    vector<int> vstd(V);

    for (int i = 0; i < V; i++)
    {
        if (vstd[i] == 0) // Calling those nodes only which are not visited
        {
            dfsHelper(i, stk, vstd, adj);
        }
    }

    vector<int> topSortd;
    while (!stk.empty()) // Stack top will be having node tht is having highest Dependencies
    {
        topSortd.push_back(stk.top()); // Lowest Indegree and Highest Outdegree
        stk.pop();
    }
    // for(auto it:topSortd) {
    //     cout << it << " ";
    // }
    // cout << endl;
    return topSortd;
}