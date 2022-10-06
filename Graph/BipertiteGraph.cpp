// A bipartite graph is possible if the graph coloring is
// possible using two colors such that vertices in a set are
// colored with the same color. Note that it is possible to
// color a cycle graph with even cycle using two colors.
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool Bfs(int i, vector<int> Adj[], vector<int> &col)
    {
        queue<int> q;
        q.push(i);
        col[i] = 1; // assign color

        while (!q.empty())
        {
            int p = q.front();
            q.pop();
            for (auto it : Adj[p])
            {
                if (col[it] == -1)
                {
                    q.push(it);
                    col[it] = col[p] == 1 ? 0 : 1;
                }

                else if (col[p] == col[it]) // if color same then not possible
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> col(V, -1);
        // 1 and 0 are color
        // col vector contain all color of vertices
        for (int i = 0; i < V; i++)
        {
            if (col[i] == -1)
            {
                if (!Bfs(i, adj, col))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}