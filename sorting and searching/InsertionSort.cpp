#include<iostream>
using namespace std;
// time complexity O(n^2)
// best case O(n)
//default adaptive if sorted then execute only in O(n) time 
//stable algorithm 
int print(int *Arr ,int n)
{
   for(int i=0;i<n;i++)
   {
       cout<<Arr[i]<<" ";
   }cout<<endl;
   return 0;
}
int insertion_sort(int *Arr ,int n)
{    int j , key;
    for(int i=1;i<=n-1;i++)  // no of passes 
    {
        key =Arr[i];
        j=i-1;      // for previous index 
       while(j>=0 && Arr[j]>key)  // for descending Arr[j]<key
       {
           Arr[j+1]=Arr[j];   
           j--;
       }
       Arr[j+1]=key;   // at last key will be inserted at correct position 
    }
    return 0;
}
/* rough work idea
  -1 0 1 2 3 4  //index

     5 7 2 9 1  //array first pass no change 
     5   7 9 1   // 2nd pass key is 2
       5 7 9 1
     2 5 7 9 1

     2 5 7 9 1   // third pass key is 9 no change

     2 5 7   9   // fourth pass key is 1 
     2 5   7 9
     2   5 7 9
       2 5 7 9
     1 2 5 7 9   // finally we got sorted array

*/
int main()
{
    int n;
    cout<<"enter size of array"<<endl;
    cin>>n;
    int Arr[n];
    cout<<"enter array element "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>Arr[i];
    }
   cout<<"array in ascending order"<<endl;
    insertion_sort(Arr,n);
    //adaptive(Arr ,n);
    print(Arr , n);
}