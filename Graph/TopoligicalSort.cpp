#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	vector<int>ans;
	
	void BFS(vector<int>adj[] , vector<int>& indegree)
	{
	    queue<int> q;
	    for(int i=0;i<indegree.size();i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i); 
	        }
	    }
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto it : adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            {
	                q.push(it);
	            }
	        }
	        
	    }
	}

	void DFS(int i,vector<int>& vis ,vector<int> adj[])
	{
	    vis[i]=1;
	    for(auto it : adj[i])
	    {
	        if(!vis[it])
	        {
	            DFS(it ,vis ,adj);
	        }
	    }
	    ans.push_back(i);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>vis(V,0);
	    vector<int>indegree(V,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	        
	    }
	    
	    BFS(adj ,indegree);
	    return ans;
	    
	    // extended code for cycle detection 
	    
	   /* if(ans.size()==V)
	    {
	        return false; // all node present not cyclic 
	    }
	    else
	    {
	        return true;  // some nodes are missing cyclic 
	    }*/
	    
	    
	    //code of DFS
	    /*for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            DFS(i ,vis ,adj);
	        }
	        
	    }
	    
	    reverse(ans.begin(),ans.end());
	    return ans;*/
	    
	}
};


/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() 
{
    int T;
    cin >> T;
    while (T--) 
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) 
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  