#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>parent;
vector<int>rankk;

// time complexity 
// brute force o(n)
// union by rank o(logn)

int findabsparent(int v)
{
   if(parent[v]==-1)
   {
       return v;  // initially parent is -1
   }
   
   // zig-zag parent
   //return findabsparent(parent[v]);

   // for path compression to rearrange to reduce search time 
   return parent[v]=findabsparent(parent[v]);
}

void unionoperation(int from ,int to)
{
    parent[from]=to;
    // from will point to to i.e to will become abs parent
}

void unionoperationforpathcompression(int from ,int to)
{
    //case 1
    // if both from and to have same rank 
    // then increase rank of connected parent 
    if(rankk[from]==rankk[to])
    {
        parent[from] =to;
        // from will point to to i.e to will become abs parent
        rankk[to]++; // increase rank of abs parent 
    }
    //case 2
    // rank remain same
    // node have more rank remain abs parent
    else if(rankk[from]>rankk[to])
    {
        parent[to]=from;  // To will point to from 
    }
    else if(rankk[from]<rankk[to])
    {
        parent[from]=to;  // from will point to To 
    }
}
bool iscycle(int V ,vector<pair<int,int>> adj)
{
   for(auto it : adj)
   {
       // to connect two vertices  connect their abs parent 
       // find will find the abs parent 
       // then we will connect them

       // lets find abs parent
       int vertex1 = findabsparent(it.first);
       int vertex2 = findabsparent(it.second);

      // if parent of both vertex1 and vertex2 is same then we can say that 
      // they belong to same set so given graph contain cycle 
      if(vertex1==vertex2)
      {
          return true;  // cycle detected 
      }
     
     // connect both parent for brute force
     //unionoperation(vertex1,vertex2);

     // for path compression 
     unionoperationforpathcompression(vertex1,vertex2);

   }
   return false; // no cycle detected
}
int main()
{
       
        int V, E;
        cin >> V >> E;  // vertex and edges

        parent.resize(V,-1);  // parent array for find operation
        rankk.resize(V,0);   // to store rank

        vector<pair<int,int>> adj; // adjecency list
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj.push_back({u,v});
        }
        if(iscycle(V,adj))
        {
            cout<<"given graph contain cycle"<<endl;
        }
        else
        {
           cout<<"given graph not contain any cycle"<<endl;
        }
    return 0;
}