#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*  data for testing 
0 1 3 
0 5 6
0 6 5
1 6 1
1 2 3
1 7 1
6 5 2
6 7 2
5 7 1
5 4 2
2 7 2
2 3 3
7 4 4
4 3 1
7 3 8
*/
void dijkstras(int V ,vector<pair<int,int>>adj[],int src)
{
   vector<int>dis(V ,INT_MAX);  // distance array

   // minheap top will always have min weight vertex
   priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
   // pair of weight ,vertex priorityqueue store
   
   pq.push({0,src});   // source to source always 0 unit distance
   dis[src]=0;

   while(!pq.empty())
   {
       int wt =pq.top().first ;   // weight 
       int ver =pq.top().second; // vertex 
       pq.pop();
        
        // traverse all adjecent vertex 
       for(auto it : adj[ver])
       {     
          int nextver =it.first;
          int weight =it.second;
           if(dis[nextver] > dis[ver]+weight)
           {
              dis[nextver]= dis[ver]+weight;
              pq.push({dis[nextver],nextver});
           }
       }
   }
   
   for(int i=0 ; i<V;i++)
   {
       cout<<"min distance from "<<src <<" to "<<i
       <<" vertex is "<<dis[i]<<endl;
   }

}
int main()
{
    int V, E;
    cout<<"enter total no of vertex and edges"<<endl;

    cin >> V >> E;  // vertex and edges

    vector<pair<int,int>> adj[V]; // adjecency list {ajdnode,weight}
    cout<<"please consider 1st vertex as 0 id means if your graph contain 4 vertex then vertex id should be 0 1 2 3"<<endl;
    cout<<"enter all edges from vertex1 to vertex2 and then enter vertex weight"<<endl;
    for (int i = 0; i < E; i++)
    {
        int u, v ,wt;
        cin>>u>>v>>wt; // from to to and weight 
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    // source vertex 
    int src;
    cout<<"enter source vertex "<<endl;
    cin>>src;
    dijkstras(V,adj ,src);
    return 0;
}