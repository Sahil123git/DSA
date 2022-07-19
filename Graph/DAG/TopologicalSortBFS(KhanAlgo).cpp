vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> inDeg(V);
    queue<int> qu;
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {                // fndng Indegree of every node
            inDeg[it]++; // Let's say there is a edge (A -> B)
        }                // THen inc indegree of B by 1
    }

    for (int i = 0; i < V; i++) // insrtng those nodes in queue which are having Indegree 0
    {
        if (inDeg[i] == 0)
        {
            qu.push(i);
        }
    }

    vector<int> topOrder;
    while (!qu.empty())
    {
        int frnt = qu.front();
        topOrder.push_back(frnt); // Instng those nodes which are having indegree 0
        qu.pop();                 // after insrtng in vctr pop this from queue also
        for (auto nbr : adj[frnt])
        {
            inDeg[nbr]--; // Dec indegree of evry nbr of ths node
            if (inDeg[nbr] == 0)
            {                 // if indegree of any node is 0, then insert tht also
                qu.push(nbr); // in queue
            }
        }
    }
    return topOrder;
}