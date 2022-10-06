// using DFS
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool DFS(vector<int> adj[], vector<int> &vis, vector<int> &dfsvis, int i)
    {
        vis[i] = 1;
        dfsvis[i] = 1;
        for (auto it : adj[i])
        {
            if (!vis[it])
            {
                if (DFS(adj, vis, dfsvis, it))
                {
                    return true;
                }
            }
            else
            {
                if (vis[it] == 1 && dfsvis[it] == 1)
                {
                    return true;
                }
            }
        }
        dfsvis[i] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> dfsvis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (DFS(adj, vis, dfsvis, i))
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
