#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph
{
    vector<pair<int, int>> *l;
    int v;

public:
    Graph(int n)
    {
        v = n;
        l = new vector<pair<int, int>>[n]; // Arr of vector of pairs
    }

    void addEdge(int x, int y, int w) // Adj list
    {
        l[x].push_back({y, w}); // y is val of node tht is prsnt other side of edge and then there is weight
        l[y].push_back({x, w}); // x node and weight
    }

    int prims()
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Qu;
        // priority will keep track of least weight edge

        bool *vstd = new bool[v]{0}; // initially all nodes are not vstd
        int ans = 0;
        Qu.push({0, 0}); // weight and nxt node
        // fst start from 0th node

        while (!Qu.empty())
        {
            auto bstNode = Qu.top(); // bst node tht we r having in the top of MinHeap
            Qu.pop();                // pop this chkd node

            int to = bstNode.second;    // this will give the value of that bst node
            int weight = bstNode.first; // this will give wgt of bstNode.first

            if (vstd[to] == 1) // chkng if bstNode is already vstd or not
            {
                continue; // if already vstd then chk another node
            }
            ans += weight; // inc weight
            vstd[to] = 1;  // mark this bstNode vstd

            for (auto it : l[to]) // here we r chkng bstNode's neighbours
            {
                if (vstd[it.first] == 0) // if it is already vstd then why to vst again
                {
                    Qu.push({it.second, it.first}); // if not vstd then push in queue
                }
            }
        }
        return ans;
    }
};
int main()
{
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(0, 3, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(2, 3, 2);

    cout << g.prims();
}