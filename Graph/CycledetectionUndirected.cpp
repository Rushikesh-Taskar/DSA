// using BFS
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool Bfs(int i, vector<int> Adj[], vector<int> &vis)
    {
        queue<pair<int, int>> q;
        q.push({i, -1});
        vis[i] = 1;

        while (!q.empty())
        {
            int node = q.front().first;
            int prev = q.front().second;
            q.pop();
            for (auto it : Adj[node])
            {
                if (!vis[it])
                {
                    q.push({it, node});
                    vis[it] = 1;
                }
                else
                {
                    if (it != prev)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (Bfs(i, adj, vis))
                {
                    return true;
                }
            }
        }
        return false;
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
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}

// using DFS

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
 {
  public:
    // Function to detect cycle in an undirected graph.

    bool DFS(vector<int> adj[] ,vector<int>& vis ,int i ,int parent)
   {
       vis[i]=1;
       for(auto it :adj[i])
       {
           if(!vis[it])
           {
               if(DFS(adj ,vis,it,i))
               {
                   return true;
               }

           }
           else
           {
               if(it!=parent)
               {
                return true;
               }

           }

       }

       return false;
   }


    bool isCycle(int V, vector<int> adj[])
    {
         vector<int>vis(V ,0);

             for(int i=0;i<V;i++)
             {
                 if(!vis[i])
                 {
                     if(DFS(adj ,vis ,i,-1))
                     {
                         return true;
                     }
                 }

             }
             return false;
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
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  */