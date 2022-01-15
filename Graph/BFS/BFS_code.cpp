#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std; //Iterative method Like Tree Lvl order Uses Queue
class graph
{
public:
    int len;
    list<int> *li;
    graph(int len)
    {
        this->len = len;
        li = new list<int>[len]; //Arr having all ele of list type
    }
    void add_edge(int vert1, int vert2, bool undir = 0)
    {
        li[vert1].push_back(vert2); //inserting ele in list at (address vert1)
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
        queue<int> q;
        bool *visited = new bool[len]{0}; //bool arr having all ele of bool type
        // bool visited[len] = {0};

        q.push(source);
        visited[source] = true;
        while (!q.empty()) //if queue is empty then stop
        {
            int frnt = q.front();
            cout << frnt << " | "; //print the front ele
            q.pop();
            for (auto it : li[frnt])
            {
                if (!visited[it]) //if the ele is already inserted then no need to insert again in queue
                {
                    visited[it] = true;
                    q.push(it); //push in queue if it is not present in the queue
                }
            }
        }
    }
};
int main()
{
    graph g(4); //can only 4 vertices
    g.add_edge(1, 2);
    g.add_edge(0, 1);
    g.add_edge(1, 3);
    g.print();
    g.bfs(0);
}