#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Dfs(int i, vector<int> adj[], vector<int> &vis)
{   
    cout<<i<<" ";
    vis[i] = 1;
    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            Dfs(it, adj, vis);
        }
    }
}

void Toposort(int i, vector<int> &vis, vector<int> adj[],stack<int>& topo)
{
    vis[i] = 1;
    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            Toposort(it, vis, adj,topo);
        }
    }
    topo.push(i);
}

void kosaraju(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    stack<int>topo;
    // step 1 find toposort
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            Toposort(i, vis, adj ,topo);
        }
    }
    
 


    // step 2 reverse direction of edges

    vector<int> trans[V];
    for (int i = 0; i < V; i++)
    {
        vis[i] = 0; // for further use
        for (auto it : adj[i])
        {
            trans[it].push_back(i);
        }
    }

    // step 3 do normal dfs on trans graph in toposort order
    while(!topo.empty())
    {     
        int node=topo.top();
        topo.pop(); 
        if (!vis[node])
        {   cout<<"SCC "<<" ";
            Dfs(node, trans, vis);
            cout<<endl;
        }
    }
}
int main()
{
    int V, E;
    cout << "enter total no of vertex and edges" << endl;

    cin >> V >> E;
    int u, v;

    vector<int> adj[V];
    cout << "enter edges from vertex u to v " << endl;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    kosaraju(V, adj);
    return 0;
}