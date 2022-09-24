#include<iostream>
using namespace std;
bool dupt(int A[], int m)
{    cout<<"duplicate no in array are: "<<endl;
     for (int i = 0; i < m;i++)
     {
         for(int j = i+1; j <m; j++)
         {  
             if(A[i]==A[j])
             {
                 cout<<A[i]<<" ";
             }
         }
     }

  
}
int main()
{
    int m;
    cout<<"enter a size of array:"<<endl;
    cin>>m;
    int A[m];
    cout<<"enter "<<m<<" element:"<<endl;
    for(int i=0;i<m;i++)
    {
         cin>>A[i];
    }
    dupt(A,m);
}