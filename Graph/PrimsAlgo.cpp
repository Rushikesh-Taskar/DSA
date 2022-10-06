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

// connection part is remaining  

void prims(int V ,vector<pair<int,int>>adj[])
{
   
   vector<int> vis(V,0);       // visited array i.e part of MST
   vector<int>parent(V,-1);    // parent array for printing mst
   vector<int>weight(V,INT_MAX); // store the weight min 
    
   parent[0]=-1;        // starting vertex dont have ant parent 

   int minweight=0;  // min spanning weight 

    // IMP NOTE 
    // insted of using priority_queue you can check min
    // weight from weight array also by traversing 

   // minheap top will always have min weight vertex
   priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
   // pair of weight ,vertex priorityqueue store 
   
   pq.push({0,0});   // start with any vertex lets start with 0th vertex weight should be 0 initially
   
   while(!pq.empty())
   {
       int wt =pq.top().first ;   // weight 

       int ver =pq.top().second; // vertex 

        pq.pop();

       if(!vis[ver])  // if not visited previously then it is par
       // of spanning tree
       {
           minweight =minweight+wt; // add its weight 
           vis[ver] =1;    //mark as visited i.e part of MST
       }
       
        // traverse all adjecent vertex 
       for(auto it : adj[ver])
       {     
          int nextver =it.first;  // adjecent vertex
          int wt =it.second;  // its weight 

           if(!vis[nextver] && weight[nextver] >wt) // not visited pussh it 
           {
              pq.push({wt,nextver});
              parent[nextver] =ver;  // change parent 
              weight[nextver]=wt;    // update weight 
           }

       }
   }
   cout<<"vertex \t weight"<<endl;
   for(int i=1;i<V;i++)
   {
       cout<<i<<" -- "<<parent[i] <<" ===>> "<<weight[i]<<endl;
   }
  cout<<"minimum weight of spanning tree is "<<minweight<<endl;

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

    prims(V,adj);
    return 0;
}