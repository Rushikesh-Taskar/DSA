#include <bits/stdc++.h>
using namespace std;

int main()
{
   
   int m;
   cout<<"enter size of hash table "<<endl;
   cin>>m;
   vector<int>v[m];
   cout<<"how many element you want to store"<<endl;
   int n;
   cin>>n;
   cout<<"enter element"<<endl;
   for(int i=0;i<n;i++)
   {
       int x;
       cin>>x;
    
       int index = x%m;  // hash function
       v[index].push_back(x);       // store in 2D vector
   }
   cout<<"hash table look like by close addressing chaining technique\n"<<endl;
   for(int i=0;i<m;i++)
   {
       cout<<i<<" ";
       for(auto j : v[i])    // for collission reduce 
       {
           cout<<"-->" << j;
       }cout<<endl;
   }

    return 0;
}
