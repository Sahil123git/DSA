#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;
class Node
{
public:
    string str;
    list<string> l;
    Node(string str)
    {
        this->str = str;
    }
};
class Graph
{
    unordered_map<string, Node *> li;

public:
    Graph(vector<string> vt)
    {
        for (auto city : vt) //every city is having it's list
        {
            li[city] = new Node(city); //this li[city] is having obj of node
        }
    }
    void addEdge(string str1, string str2, bool undir = false)
    {
        (li[str1]->l).push_back(str2); //li[str] is having obj of class Node and this is ptr
        if (undir)
        {
            li[str2]->l.push_back(str1); //pushing values in list
        }
    }
    void ptr_list()
    {
        for (auto it : li)
        {
            cout << it.first << "-->";
            for (auto iit : it.second->l) //it.second->l this is pointing to list in node class
            {
                cout << iit << ",";
            }
            cout << endl;
        }
    }
};
int main()
{
    vector<string> cty = {"Delhi", "London", "Paris", "New York"};

    Graph g(cty);
    g.addEdge("Delhi", "London");
    g.addEdge("Paris", "New York");
    g.addEdge("Delhi", "New York");
    g.addEdge("London", "New York");
    g.ptr_list();
}
