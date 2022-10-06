#include <bits/stdc++.h>

using namespace std;
bool com(int a,int b)  //comparator
{
    if(a>=b)
    {
        return true;
    }
    return false;
}
int main()
{
    int arr[4]={4,6,2,9};
    sort(arr,arr+4);
    cout<<"next permutation"<<endl;
    do
    {
      for(auto it:arr)
      {
          cout<<it<<" ";
      }
      cout<<endl;
    }while(next_permutation(arr,arr+4));
   
   
   sort(arr,arr+4,com);
   cout<<"previous permutation"<<endl;
    do
    {
      for(auto it:arr)
      {
          cout<<it<<" ";
      }
      cout<<endl;
    }while(prev_permutation(arr,arr+4));
  
  
    return 0;
}