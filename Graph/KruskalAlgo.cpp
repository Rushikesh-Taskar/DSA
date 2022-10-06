#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>parent;

int findabsparent(int v)
{
   if(parent[v]==-1)
   {
       return v;  // initially parent is -1
   }
   // zig-zag parent
   return findabsparent(parent[v]);
}

void unionoperation(int from ,int to)
{
    parent[from]=to;
    // from will point to to i.e to will become abs parent
}

bool iscycle(int first , int second)
{
   
       // to connect two vertices  connect their abs parent 
       // find will find the abs parent 
       // then we will connect them

       // lets find abs parent
       int vertex1 = findabsparent(first);
       int vertex2 = findabsparent(second);

      // if parent of both vertex1 and vertex2 is same then we can say that 
      // they belong to same set so given graph contain cycle 
      if(vertex1==vertex2)
      {
          return true;  // cycle detected 
      }
     
     // connect both parent 
     unionoperation(vertex1,vertex2);

   return false; // no cycle detected
}

void kruskal(priority_queue<pair<int , pair<int,int>> ,vector<pair<int , pair<int,int>>> , greater<pair<int,pair<int,int>>>> adj ,int v)
{
    
    parent.resize(v,-1);
    int cost=0;
    while(!adj.empty())
    {
        int w = adj.top().first; // weight
        int u = adj.top().second.first; // u vertex
        int v = adj.top().second.second; // v vertex 
        adj.pop();

         if(!iscycle(u,v))
         {
            cout<<u<<"---"<<v<<"===>"<<w<<endl;
            cost = cost+w;
         }
    }
    cout<<"minimum weight of MST is "<<cost<<endl;
}
int main()
{
     int V, E;
    cout<<"enter total no of vertex and edges"<<endl;

    cin >> V >> E;  // vertex and edges

    priority_queue<pair<int , pair<int,int>> ,vector<pair<int , pair<int,int>>> , greater<pair<int,pair<int,int>>>> adj;  
   
    cout<<"please consider 1st vertex as 0 id means if your graph contain 4 vertex then vertex id should be 0 1 2 3"<<endl;
    cout<<"enter all edges from vertex1 to vertex2 and then enter vertex weight"<<endl;
    for (int i = 0; i < E; i++)
    {
        int u, v ,wt;
        cin>>u>>v>>wt; // from to to and weight 
        adj.push({wt,{u,v}});
    }
    
    kruskal(adj,V);
    return 0;
}