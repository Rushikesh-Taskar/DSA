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
    int a;
    cout<<"enter a index for delete an element from that position :"<<endl;
    cin>>a;
    for(int i=a;i<m-1;i++)
    {
        A[i]=A[i+1];                   //create a empty space 6=7 but it means 7=6
    }
    m--;
    for(int i=0;i<m;i++)
    {
         cout<<A[i]<<" ";
    }
}
//for inserting last element at delated position 
/*#include<iostream>
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
    cout<<"enter a index of element for delete :"<<endl;
    cin>>a;
    m=m-1;
    A[a]=A[m];
    //A[a]=A[m-1];
    //m--;

   for(int i=0;i<m;i++)
    {
         cout<<A[i]<<" ";
    }
    return 0;
} */