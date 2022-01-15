#include <iostream> //Only for undirected Graph
#include <list>     //because in directed graph the closest edge can be incoming
#include <queue>    //one also
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
    void add_edge(int vert1, int vert2, bool undir = 1) //this is for bidirectional graph
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
    void bfs(int source, int dest = -1)
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
        parent[source] = source;
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
        if (dest != -1)
        {
            int temp = dest;
            while (temp != source)
            {
                cout << temp << "-->";
                temp = parent[temp];
            }
            cout << source;
        }
    }
};
int main()
{
    graph g(5); //can only 5 vertices(0,1,2,3,4)
    g.add_edge(0, 1);
    g.add_edge(2, 0);
    g.add_edge(3, 2);
    g.add_edge(4, 3);
    g.add_edge(1, 4);
    // g.print();
    g.bfs(0, 3); //starting pt is 0 and finding path of 3
}