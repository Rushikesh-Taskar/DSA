#include<iostream>
using namespace std;

int binary_search(int A[],int start,int end,int key) 
{  //start is index of starting position and 
//end is index of last position it will change according to condition 
// recursive process  (recursion)
   int mid;
   if(end>=start)
   {
      mid=(start+end)/2;
      if(A[mid]==key)
      {
         return mid;
      }
      else if(key>A[mid])
      {
        return binary_search(A,mid+1,end,key);
      }
      else if(A[mid]>key)
      {
        return binary_search(A,start,mid-1,key);
      }

   }
   return -1;
}
int main()
{
    int n;
    cout<<"enter size of array"<<endl;
    cin>>n;
    int Arr[n];
    //array should be sorted 
    cout<<"enter array element "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>Arr[i];
    }
    int key;
    cout<<"enter  element to search in array"<<endl;
    cin>>key;
    int result =binary_search(Arr,0,n-1 ,key);

    if(result==-1)
    {
        cout<<key <<" is not present in array"<<endl;
    }
    else
    {
        cout<<key <<" is  present at "<<result <<" position "<<endl;
    }
}