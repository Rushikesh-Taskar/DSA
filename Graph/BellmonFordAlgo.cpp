#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        vector<int> dis(n, INT_MAX);
        int src=0;  // lets start with 0th vertex
        dis[src] = 0; 

        for (int i = 0; i < n - 1; i++) // n-1 relaxation
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dis[u] != INT_MAX && dis[u] + wt < dis[v])
                {
                    dis[v] = dis[u] + wt;
                }
            }
        }

        for (auto it : edges) // one more relaxation
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dis[u] != INT_MAX && dis[u] + wt < dis[v]) // if distance still reducing then their is -ve cycle
            {
                return 1;
            }
        }
        for(int i=1;i<n;i++)
        {
            cout<<"distance from "<<src<<" to "<<i<<" is "<<dis[i]<<endl;
        }
        return 0;
    }
};

int main()
{
    
        int n, m;
        cout<<"enter total no of vertex and edges"<<endl;
        cin >> n >> m;

        vector<vector<int>> edges;
        cout<<"enter vertex u to v and then weight"<<endl;
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({x, y, z});
        }
        Solution obj;
        int ans = obj.isNegativeWeightCycle(n, edges);
        if(ans)
        {
            cout<<"graph contain negative cycle "<<endl;
        }
    
    return 0;
}