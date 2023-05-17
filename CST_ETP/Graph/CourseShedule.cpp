class Solution
{
public:
    vector<int> find0Indegree(vector<vector<int>> &adj, queue<int> &qu)
    {
        int n = adj.size();
        vector<int> InDegree(n);

        for (auto node : adj)
        {
            for (auto nbr : node)
            {
                InDegree[nbr] += 1; // inc indegree of every node
            }
        }

        for (int i = 0; i < n; i++)
        { // finding nodes with InDegree 0
            if (InDegree[i] == 0)
            {
                qu.push(i);
            }
        }

        return InDegree;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &preq)
    { // Detect Cycle Using BFS (Khan's Algo)
        int n = numCourses;
        vector<vector<int>> adj(n, vector<int>());

        for (int i = 0; i < preq.size(); i++)
        { // making adj list
            adj[preq[i][1]].push_back(preq[i][0]);
        }

        queue<int> zeroInd; // initially having nodes with inDegree 0

        vector<int> InDegree = find0Indegree(adj, zeroInd), res; // in res we'll save correct order
        int cnt = 0;

        while (!zeroInd.empty())
        {
            int node = zeroInd.front();
            zeroInd.pop();

            for (auto it : adj[node])
            { // dec Indegree of it's nbr
                InDegree[it]--;

                if (InDegree[it] == 0)
                {
                    zeroInd.push(it);
                }
            }
            res.push_back(node);
            cnt++;
        }

        if (cnt == n)
        { // means there is way
            return res;
        }
        else
        { // means there is no way to cmpl all courses
            return {};
        }
    }
};