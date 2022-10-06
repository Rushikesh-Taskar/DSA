#include<bits/stdc++.h>
using namespace std;
int main()
{
    multimap<char ,int>mp;
    cout<<mp.size()<<endl;
    mp.insert({'a',5});
    mp.emplace('b',6);
    mp.insert(make_pair('c',7));
     mp.insert({'a',6});
      mp.insert({'a',9});
      
    for (auto it:mp)
    {
           cout<<it.first<<" "<<it.second<<endl;
    }
   mp.erase(mp.begin(),mp.find('b'));
   cout<<"after erase function "<<endl;
   for (auto it:mp)
    {
           cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<"last element of multimap"<<endl;
    //auto p=mp.rbegin();
    //cout<<p->first<<" "<<p->second<<endl;
    
}