#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;
class Graph
{
public:
    int V;
    vector<pair<int, int>> *adj;
    // int *ptr = new int[10];

    Graph(int V)
    {
        this->V = V;
        adj = new vector<pair<int, int>>[V];
    }
    void addEdge(int v, int u, int w)
    {
        adj[v].push_back({u, w});
        adj[u].push_back({v, w}); // becoz this is undirected graph
    }

    vector<int> DijkstraAlgo(int Source) // Dijkstra Algo
    {
        vector<int> distV(V, INT_MAX); // all ele initialized with max_int value
        distV[Source] = 0;             // dist of source to source is 0

        // using set so that we can have smallest weight(Dist) ele at the 1st locn
        set<pair<int, int>> lowDist; // pair of Dist and nxt node
        lowDist.insert({0, Source}); // pair of (Dist and ele)

        while (!lowDist.empty())
        {
            auto it = lowDist.begin(); // this is lowest dist ele in set
            int wgt = it->first;       // dist of prev node to cur node is wgt
            int node = it->second;     // the node
            lowDist.erase(it);         // remove this lowest ele from set also

            for (auto nbr : adj[node]) // chkng lowest wgt node, nbrs
            {
                int ele = nbr.first;
                int dist = nbr.second;

                if (dist + wgt < distV[ele]) // if (dist to this nbr(dist) + prev Node to cur node dist(wgt)) is less than prev dist tht was in arr
                {                            // then chng the dist in distV
                    auto f = lowDist.find({distV[ele], ele});
                    if (f != lowDist.end())
                    {
                        lowDist.erase(f); // if this ele is already in set then remove tht
                    }
                    distV[ele] = dist + wgt;           // updating dist arr with new shortest dist
                    lowDist.insert({distV[ele], ele}); // insert this updtd dist in set
                }
            }
        }
        return distV;
    }
};
int main()
{
    Graph g(9); // https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-set-in-stl/
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    vector<int> Darr = g.DijkstraAlgo(0);
    for (int i = 0; i < 9; i++)
    {
        cout << Darr[i] << " ";
    }
}