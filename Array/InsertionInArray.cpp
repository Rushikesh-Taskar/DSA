#include<iostream>
using namespace std;

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
    int a,b;
    cout<<"enter a position and element for inserting in array resp. :"<<endl;
    cin>>a>>b;
   
    for(int i=m;i>=a;i--)
    {
        A[i]=A[i-1];                       //code for create a space in array for insertion
    }
    A[a]=b;
     m++;                                 //increase the size of array
    for(int i=0;i<m;i++)
    {
         cout<<A[i]<<" ";
    }
    return 0;
    int temp;

}
//for interchanging position of array at last position
/*
#include <iostream>

using namespace std;

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
    int a,b;
    cout<<"enter a position and element for inserting in array resp. :"<<endl;
    cin>>a>>b;
    m=m+ 1;
    A[m-1]=A[a];
    A[a]=b;
    
    for(int i=0;i<m ;i++)
    {
        cout<<A[i]<<" ";
    }

    return 0;
}*/