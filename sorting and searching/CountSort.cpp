#include<iostream>
using namespace std;

int count_sort(int *A,int n,int maxele)
{  
    int B[maxele+1];  // creating new array with size maxelement+1
                      // index from 0
    
    // initilizing new array element with 0
    for(int i=0;i<maxele+1;i++)
    {
        B[i]=0;
    }
    // for calculate how many time element is present 
    for(int i=0;i<n;i++)
    {
        B[A[i]]++;
    }

    int j=0; // for B array 
    int k=0;  // for A array
    while(j<=maxele)
    {
        if(B[j]!=0)  // if element is not 0 then add index int A array 
        {            // and move k by k+1
            A[k]=j;
            B[j]--;
            k++;
        }
        else
        {
            j++;   // if element is zero then move pointer of B (Max array)
                    // by 1 k+1
        }
    }
    return 0;
}

int print(int *Arr ,int n)
{
   for(int i=0;i<n;i++)
   {
       cout<<Arr[i]<<" ";
   }cout<<endl;
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

   // calculate max element from array
   int maxelement = Arr[0];
   for(int i=1;i<n;i++)
   {
       if(Arr[i]>maxelement)
       {
           maxelement=Arr[i];
       }
   }

   cout<<"array in ascending order"<<endl;
    count_sort(Arr,n ,maxelement);
    print(Arr , n);
}