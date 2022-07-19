#include <iostream>
#include <queue>

const int N = 1e5 + 10;
const int INF = 1e9 + 10;
using namespace std;

// vector<pair<int, int>> gr[N];
vector<pair<int, int>> *gr;
vector<int> lvl(N, INF);

void BFS_0_1()
{
    deque<int> dq;
    dq.push_back(1);
    lvl[1] = 0;

    while (!dq.empty()) // this algo can also be used for shortest path from source to other nodes(Like Dijkstra Algo), but this will chk edge multiple times which can inc the TC
    {
        int curEle = dq.front();
        dq.pop_front();
        for (auto nbr : gr[curEle])
        {
            int ele = nbr.first;
            int wt = nbr.second;
            if (lvl[curEle] + wt < lvl[ele])
            {
                lvl[ele] = lvl[curEle] + wt;
                if (wt == 1)
                {
                    // cout << "now here";
                    dq.push_back(ele);
                }
                else if (wt == 0) // 0 is like lowest wt so insert at the front
                {
                    // cout << "here";
                    dq.push_front(ele);
                }
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;

    gr = new vector<pair<int, int>>[n + 1];

    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;

        if (x == y) // for fixing self loops case
        {
            continue;
        }
        gr[x].push_back({y, wt});
        gr[y].push_back({x, wt});
    }
    BFS_0_1();

    for (int i = 1; i <= n; i++)
    {
        cout << lvl[i] << " ";
    }
}