#include <bits/stdc++.h>

using namespace std;
bool com(pair<int,int>a,pair<int,int>b)
{
    if(a.first<b.first)
    {
        return true;
    }
    else if(a.first==b.first)
    {
     if(a.second>=b.second)
     {
        return true;
     }
    }
    return false;
}
int main()
{ 
    //print pair in ascending order if both element of pair are equal then 
    //print descending order according to second element
    
    vector<pair<int,int>>arr={{9,7},{7,8},{9,9},{9,4}};
    
   
   sort(arr.begin(),arr.end(),com);
   // com if it's false then it will swap the pair
   
     for(auto it:arr)
      {
          cout<<it.first<<" "<<it.second <<endl;
      }
      cout<<endl;
   
  
  
    return 0;
}