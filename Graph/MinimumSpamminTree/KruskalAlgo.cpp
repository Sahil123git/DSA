#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU
{
    int V, *Parr, *rank;

public:
    DSU(int size)
    {
        V = size;
        Parr = new int[size];
        rank = new int[size];

        for (int i = 0; i < V; i++)
        {
            Parr[i] = i;
            rank[i] = 1; // initially rank is 1
        }
    }

    // Now funcs of DSU
    int find(int val) // for fndng root lvl parent
    {
        if (val == Parr[val]) // base condn
        {
            return val;
        }
        return Parr[val] = find(Parr[val]); // this is path compression
    }

    void unionSet(int i, int j)
    {
        int fst = find(i);
        int scnd = find(j);

        if (fst != scnd)
        {
            if (rank[fst] < rank[scnd])
            {
                Parr[fst] = scnd;
                rank[scnd] += rank[fst]; // increment the rank of scnd by (rank of fst)
            }
            else
            {
                Parr[scnd] = fst;
                rank[fst] += rank[scnd];
            }
        }
    }
};

class Graph
{
    vector<vector<int>> edgeList; // one edge is having 3 things weight, nodes that are present in both ends of edge
    int v;

public:
    Graph(int V)
    {
        this->v = V;
    }

    void addEdge(int x, int y, int wt)
    {
        edgeList.push_back({wt, x, y}); // now if we sort this it will be sorted acc to weight
    }

    int kruskal()
    {
        sort(edgeList.begin(), edgeList.end()); // here we r sorting acc to weight
        DSU s(v);
        int weight = 0;
        for (auto it : edgeList) // chk all nodes of edge list
        {
            int wt = it[0];
            int x = it[1];
            int y = it[2];

            if (s.find(x) != s.find(y)) // if root lvl par of both nodes is diff then only add it's weight
            {
                weight += wt;
                s.unionSet(x, y); // now make par of x and y same
            }
        }
        return weight;
    }
};
int main()
{
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(3, 2, 4);
    g.addEdge(2, 0, 2);
    g.addEdge(2, 0, 2);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 2);

    cout << g.kruskal();
}
