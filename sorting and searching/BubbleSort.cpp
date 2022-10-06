#include<iostream>
using namespace std;
//sorting in incresing order
// time complexity O(n^2)
//best case O(n);
//by default not adaptive but by using issort function it will become adaptive

int bubble_sort(int *Arr ,int n)
{   
    for(int i=0;i<n-1;i++)  // n-1 = size-1 = no of passes
    {  
       
       for(int j=0;j<n-1-i;j++)  // n-1-i because last element is 
       {                         // always maximum 
           if(Arr[j]>Arr[j+1])
           {   //swap two array element 

               int temp;
               temp=Arr[j];
               Arr[j]=Arr[j+1];
               Arr[j+1]=temp;
               //swap(Arr[j],Arr[j+1]);
           }
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

int adaptive(int *Arr ,int n)
{  int issorted=0;

   for(int i=0;i<n-1;i++)  // n-1 = size-1 = no of passes
    {  
       issorted =1;
       for(int j=0;j<n-1-i;j++)  // n-1-i because last element is 
       {                         // always maximum 
           if(Arr[j]>Arr[j+1])
           {   //swap two array element 

               int temp;
               temp=Arr[j];
               Arr[j]=Arr[j+1];
               Arr[j+1]=temp;

               issorted=0;
               //swap(Arr[j],Arr[j+1]);
           }
       }
       if(issorted)
       {
           return 0;
       }

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
    bubble_sort(Arr,n);
    //adaptive(Arr ,n);
    print(Arr , n);
}