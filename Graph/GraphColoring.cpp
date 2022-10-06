
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class color
{
public:
    int cancolor(vector<int> col, vector<int> adj[], int vertex, int V)
    {

        vector<int> adjcol(V, -1);

        // set all adjecent colors id in adjcol vector so that no two adjecent vertex will get same color
        for (auto it : adj[vertex])
        {
            if (col[it] != -1)
            {
                adjcol[col[it]] = 1;
            }
        }

        // check min color
        int i = 0;
        for (i = 0; i < V; i++)
        {
            if (adjcol[i] == -1)
            {
                break;
            }
        }
        return i; // color to assign return its id
    }
    void mincolor(int V, vector<int> adj[])
    {
        vector<int> col(V, -1);
        col[0] = 0; // vertex 0 will be of 0 id color

        int choramaticno = INT_MIN;

        // check all vertex
        for (int i = 1; i < V; i++)
        {
            int color = cancolor(col, adj, i, V);
            col[i] = color; // assign color

            choramaticno = max(choramaticno, color); // find chromatic no
        }

        // print color id of all vertices
        for (int i = 0; i < V; i++)
        {
            cout << "vertex " << i << " is color by " << col[i] << endl;
        }

        cout << "choramatic no of graph is " << choramaticno + 1 << endl; // choramaticno+1 because 0 based indexing

        // for m color problem
        /*if(choramaticno+1>m) // for m color problem
        {
            return false;
        }
        else
        {
            return true;
        }*/
    }
};

int main()
{
    int V, E;
    cout << "please enter 0 based indexing means first vertex should be 0" << endl;
    cout << "enter count of vertices and edges resp." << endl;
    cin >> V >> E;

    vector<int> adj[V];
    cout << "enter all edges " << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    color c1;
    c1.mincolor(V, adj);
}