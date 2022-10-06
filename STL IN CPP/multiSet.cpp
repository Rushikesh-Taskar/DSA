#include<bits/stdc++.h>

using namespace std;
int main()
{
   multiset<int> ms;
   // in ascending order but duplicates are allowed
   ms.insert(3);
   ms.insert(4);
   ms.insert(5);
   ms.insert(6);
   ms.insert(3);
   ms.insert(4);
   ms.insert(3);
   ms.insert(4);
   ms.insert(7);
   
   for (auto i :ms)
   {
       cout<<i<<" ";
   }cout<<endl;
   cout<<"count of 3 are : "<<ms.count(3)<<endl;
   ms.erase(3);     //erase all 3
   ms.erase(ms.find(4));  //first 4
   cout<<"after deleting 3"<<endl;
   for (auto i :ms)
   {
    cout<<i<<" ";
   }cout<<endl;
  auto b=ms.find(5);
  //cout<<*b<<endl;
  auto p= lower_bound(ms.begin(),ms.end(),7);
  cout<<*p;
  
 

}