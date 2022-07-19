void floydWarshall(int graph[V][V])
{
    for (int k = 0; k < V; k++) // for updating shortest dist in Adjacency Matrix
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
                {
                    graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
                }
            }
        }
    }

    for (int i = 0; i < V; i++) // for chkng every diagonal ele
    {
        if (graph[i][i] < 0) // if after processing any diagonal ele is -ve means, -ve weight cycle exist
        {
            cout << "-ve edge weight cycle is present";
        }
    }

    for (int i = 0; i < V; i++) // this will give shortest path from every node to every other node(All pair shortest path)
    {
        for (int j = 0; j < V; j++)
        {
            cout << "Dist from " << i << " to " << j << " is " << graph[i][j] << endl;
        }
        cout << "--------------------------------------------------------" << endl;
    }
}
// TC: O(n^3)
// SC: O(1)