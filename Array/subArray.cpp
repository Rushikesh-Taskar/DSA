#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter size of array"<<endl;
    cin>>n;
    int A[n];
    cout<<"enter array element"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    
    cout<<"possible subarrays are:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k=i;k<=j;k++)   //time complexity O(n^3)
            {
                cout<<A[k]<<" ";
            }
            cout<<endl;
        }
    }

    int sum=0 ,mul=1;
    int max_no=0;

   //Kadane's algorithm  for subarray of sum is max
   for(int i=0;i<n;i++)
   { 
       sum=sum+A[i];
       if(sum<0)
       {
           sum=0;
       }
       max_no=max(sum,max_no);
   }

   cout<<"max sum of sub array is : "<<max_no<<endl;
}