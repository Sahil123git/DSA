#include <iostream>
#include <list>
#include <queue>
using namespace std;
class graph
{
public:
    int len;
    list<int> *li;
    graph(int len)
    {
        this->len = len;
        li = new list<int>[len];
    }
    void add_edge(int vert1, int vert2, bool undir = 0)
    {
        li[vert1].push_back(vert2);
        if (undir)
        {
            li[vert2].push_back(vert1);
        }
    }
    void print()
    {
        for (int i = 0; i < len; i++)
        {
            cout << i << "-->";   //every i is having it's own list
            for (auto it : li[i]) //for printing i's list
            {
                cout << it << ",";
            }
            cout << endl;
        }
    }
    void bfs(int source)
    {
        // bool chkr[len] = {0};
        bool *chkr = new bool[len]{0};
        // bool chkr[source] = {0};
        int *dist = new int[len]{0};
        // int chkr[source] = {0};
        vector<int> parent(len, -1);

        queue<int> qu;
        qu.push(source);
        chkr[source] = 1;
        dist[source] = 0;
        parent[source] = 0;
        while (!qu.empty())
        {
            int frnt = qu.front();
            cout << frnt << " ";
            qu.pop();

            for (auto it : li[frnt])
            {
                if (!chkr[it])
                {
                    chkr[it] = 1;
                    qu.push(it);
                    dist[it] = dist[frnt] + 1; //this all we are storing in the arr dist arr there is no list
                    parent[it] = frnt;
                }
            }
        }
        cout << endl;
        for (int i = 0; i < len; i++) //for dist
        {
            cout << "shortest path from 0: " << dist[i] << endl;
        }
    }
};
int main()
{
    graph g(4); //can only 3 vertices
    g.add_edge(1, 2);
    g.add_edge(0, 1);
    g.add_edge(1, 3);
    g.print();
    g.bfs(0); //starting pt is 0
}