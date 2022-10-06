#include <bits/stdc++.h>

using namespace std;

// this implementation is also called as tarjan's algorithm 
class bridge
{
public:
    int totalbridgeedges = 0;

    void DFS(int node, int parent, int timer, vector<int> &vis, vector<int> &tim, vector<int> &low, vector<int> adj[])
    {

        low[node] = tim[node] = timer++; // increase time
        vis[node] = 1;                   // mark is visited

        // traverse through all vertices
        for (auto it : adj[node])
        {
            if (it == parent) // if adj is parent no need to do anything
            {
                continue;
            }

            if (!vis[it])
            {
                DFS(it, node, timer, vis, tim, low, adj); // call dfs

                low[node] = min(low[node], low[it]); // collect min time from adj vertices

                if (low[it] > tim[node]) // removal condition
                {
                    totalbridgeedges++;
                    cout << "bridge edge is from " << node << " to " << it << endl; // print bridge
                }
            }
            else
            {
                low[node] = min(low[node], tim[it]); // update min time
            }
        }
    }

    void isbridge(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> tim(V, -1); // visiting time
        vector<int> low(V, -1); // lower time from adj vertex
        int timer = 0;          // for visiting time

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                DFS(i, -1, timer, vis, tim, low, adj); // call dfs
            }
        }

        cout << "total bridge point are " << totalbridgeedges << endl;
    }
};

int main()
{
    int V, E;
    cout << "enter total count of vertex and edges " << endl;
    cin >> V >> E;

    vector<int> adj[V];

    cout << "enter all vertices from u to v one by one " << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bridge b1;
    b1.isbridge(V, adj);

    return 0;
}