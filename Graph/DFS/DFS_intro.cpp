#include <iostream>
#include <list>
#include <queue>
using namespace std; //DFS Recursive mthod for both undirected and directed
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

    void dfs_hlpr(bool chkd[], int source) //bool arr is passed by ref so chngs will reflect
    {
        chkd[source] = true;       //the node which we have enetered it will make that node 1
        cout << source << ", ";    //printing that node
        for (auto it : li[source]) //callng all it's adjacent nodes of this (source)NODE
        {
            if (!chkd[it]) //If the adjacent node is chkd don't call it Recursively
            {
                dfs_hlpr(chkd, it);
            }
        }
    }
    void dfs(int source)
    {
        // bool chkd[len] = {0}; //default all are not chkd
        bool *chkd = new bool[len]{0};//or this every ele is of type bool 
        dfs_hlpr(chkd, source);
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

    g.dfs(0); //starting pt is 0 and finding path of 3
}