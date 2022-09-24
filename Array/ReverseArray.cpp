#include<iostream>
using namespace std;
int arr(int A[],int m)
{
       for(int i = 0; i<m/2 ;i++)
       {
           int temp;
           temp=A[i];
           A[i]=A[m-1-i];
           A[m-1-i]=temp;
       } 
       cout<<"array after reversing :"<<endl;
       for(int i=0;i<m;i++)
       {
           cout<<A[i]<<" ";
       }

}


int main()
{  
    int m;
     cout<<"enter a size of array :"<<endl;
     cin>>m;
    int A[m];
    cout<<"enter element: "<<endl;
    for(int i = 0; i < m; i++)
    {
        cin>>A[i];
    }
    cout<<"Array before reversing :"<<endl;
    for(int i = 0; i < m; i++)
    {
        cout<<A[i]<<" ";
    }
    /*for(int i=m-1;i>=0;i--)
    {
        cout<<A[i]<<" ";
    }*/
    cout<<endl;
    arr(A,m);
    return 0;
}