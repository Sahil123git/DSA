#include <iostream>
#include <list>
using namespace std;
class graph
{
    int v;
    list<int> *li; //data type of li is list<int>*

public:
    graph(int v)
    {
        this->v = v;
        li = new list<int>[v]; //this is V size of linkedlists or(Arr of LL)
        //similar to (int *arr= new int[10];) this is 10 eles of int type in the arr
    }
    void add_edge(int i, int j, bool undir = 1)
    {
        li[i].push_back(j); //it is like a veritical list in which we are adding vertices which are connected to that list which transform it to Arr of Lists
        if (undir)
        {
            li[j].push_back(i);
        }
    }

    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << "-->";   //every i is having it's own list
            for (auto it : li[i]) //for printing i's list
            {
                cout << it << ",";
            }
            cout << endl;
        }
    }
};
int main()
{

    graph g(4); //it means u can add 4 vertices only(0,1,2,3)

    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.print();
}
