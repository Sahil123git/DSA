#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int v;
    list<pair<int, int>> l;

public:
    Graph(int v)
    {
        this->v = v;
    }
    void addEdge(int u, int v)
    {
        l.push_back(make_pair(u, v));
    }

    int fndSet(int i, int par[]) // For fndng topMost parent
    {
        if (par[i] == -1)
        {
            return i;
        }
        return fndSet(par[i], par);
    }

    void union_set(int x, int y, int par[]) // for mkng X's par as Parent of Y's par
    {
        int parX = fndSet(x, par); // fndng root lvl par of both nodes
        int parY = fndSet(y, par);

        if (parX != parY) // if both child having diff par
        {
            par[parY] = parX; // then connect
        }
    }

    bool containsCycle() // chkng if there exist a cycle or not
    {
        int *par = new int[v];
        for (int i = 0; i < v; i++) // initially par of every node is -1
        {
            par[i] = -1;
        }

        for (auto edge : l) // chkng every edge
        {
            int i = edge.first;
            int j = edge.second;

            int pari = fndSet(i, par);
            int parj = fndSet(j, par);

            if (pari == parj) // if par of both nodes is same then cycle exists
            {
                return 1;
            }
            else // otherwise cnct both par
            {
                union_set(i, j, par);
            }
        }
        return 0;
    }
};
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    cout << g.containsCycle();
}