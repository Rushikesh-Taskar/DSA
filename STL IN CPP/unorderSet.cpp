#include<bits/stdc++.h>

using namespace std;


int main()
{
    unordered_set <int> s;
  
     for(int i=0;i<=10;i++)
     {
        s.emplace(i);  //s.insert(i);  
     }
     
     for(auto i:s)
     {
       cout<<i<<" ";
     }
     cout<<endl;
     //auto i=s.find(4);
    // cout<<*i<<endl;
   // unordered_set<int> p;
   //swap(p,s);   // p.swap(s)
  // cout<<s.count(4);   // how many time element 4 is present

     
}