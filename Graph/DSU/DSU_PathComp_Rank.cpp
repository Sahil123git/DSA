#include <iostream>
#include <list>
using namespace std;
// Concpt from: https://www.youtube.com/watch?v=Kptz-NVA2RE
// Here (Rank and Path compression) both will dec the Time complexity
// O(4 alpha) which can be considered as O(1)
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
        if (par[i] != i)
        {
            par[i] = fndSet(par[i], par); // path compresssion
            /*here we are removing the old par link and adding direct link to Top root node(Par), for all those nodes in which we r getting new par (this will dec the TC when ever we want to reach at the top par node from this node again)*/
        }
        return par[i];
    }

    void union_set(int x, int y, int par[], int rank[]) // for chng par of less rank Root node
    {
        int parX = fndSet(x, par); // fndng root lvl par of both nodes
        int parY = fndSet(y, par);

        if (parX != parY) // if both child having diff par
        {
            if (rank[parX] > rank[parY]) // here we fndng whose rank is less means which is having less child nodes (Less rank par will become child of Greater rank par)
            {
                par[parY] = parX;         // here parY is child node of parX node
                rank[parX] += rank[parY]; // changng the rank of root node (i.e parX)
            }
            else
            {
                par[parX] = parY;
                rank[parY] += rank[parX]; // now rank of (bigger-rank) node will inc by rank of less rank node
            }
        }
    }

    bool containsCycle() // chkng if there exist a cycle or not
    {
        int *par = new int[v];
        int *rank = new int[v];

        for (int i = 0; i < v; i++) // initially par of every node is -1
        {
            par[i] = i;  // initially every node filled with it's value
            rank[i] = 1; // rank will be 1 initially
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
            else // other wise cnct both par
            {
                union_set(i, j, par, rank);
            }
        }
        return 0;
    }
};
int main()
{
    Graph g(7);
    g.addEdge(0, 1); // Here we r making edge List
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 4);
    g.addEdge(5, 6);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    cout << g.containsCycle();
}