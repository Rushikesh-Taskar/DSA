#include<bits/stdc++.h>

using namespace std;

int main()

{
    map<string , int> mp;   //string is key and int is value
    map<char, int> mp1{{'a',10},{'b',20},{'c',30}};   
    mp["hii"]=4;
    mp["hello"]=7;
    mp["byy"]=9;

    mp["hii"]=8;         //overried with first hii key

   cout<<mp["hii"]<<endl;

   mp.emplace("no",99);   //insert
   mp.insert(make_pair("noo",89));
   mp.emplace("no",87);  //not change value
   mp["no"]=997;            //change the value

   //mp.erase("no");   //erase only value and make it 0

   cout<<mp["no"]<<endl;
   
   //print key and value pair
  /* for (auto i = mp.begin(); i != mp.end();i++) 
   {
       cout<<i->first<<" "<<i->second<<endl;
   }*/
   //by using for each loop

   /*for(auto i:mp)
   {
       cout<<i.first<<" "<<i.second<<endl;
   }*/

   //cout<<mp1.at('c')<<endl;   //value of c key
   //cout<<mp1['b']<<endl;
   //mp1['b']++;    //increase value of key by 1
   // cout<<mp1['b']<<endl;
}