#include<iostream>
using namespace std;
 
// time complexity O(n^2)
//not Adaptive by default 
// minimum element of array should be in left part

int print(int *Arr ,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<Arr[i]<<" ";
    }cout<<endl;
    return 0;
}

int selection_Sort(int *Arr,int n)
{    int min;
    for(int i=0;i<n;i++)
    {   
        min= Arr[i];  // store minimum element
        int minindex=i;       //for change index in line no 29 30
        for(int j=i+1;j<n;j++) 
        {
            if(min>Arr[j])  //for descending order min<Arr[j]
            {
               min=Arr[j];
               minindex=j;
            }
        }
       // swap between two index element
        int temp=Arr[i]; 
        Arr[i]=min;
        Arr[minindex]=temp;

    }
    return 0;
}
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
   selection_Sort(Arr,n);
   print(Arr,n);
}