#include<bits/stdc++.h>
using namespace std;

int partitioning(int *A ,int low ,int high)
{
    int pivot =A[low];  // pivot at first element
    int i=low+1;      // pivot +1 index
    int j=high;       // last index
    do
    {
      // check greater element only than pivot
      //if smallest or equal element found than increment
    
      while(A[i]<=pivot)  
      {
        i++;
      }
      // check smaller or equal element than pivot
      // if greater element found than decrement
      while(A[j]>pivot)
      {
        j--;
      }
      // if we get smallest and gretest element than pivot than 
      // swap between them
      if(j>i)
      {
          int temp =A[j];
          A[j]=A[i];
          A[i]=temp;

         // swap(A[i],A[j]);
      }

    }while(j>i);
     
     // if j become smaller or equal to pivot than 
     // swap between pivot and j position
    int temp = A[j];
    A[j]=pivot;
    A[low]=temp;
    
    // return pivot position means j 
    // for next prtitioning in left and right of pivot
    return j;
}
int print(int *A ,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}
int Quicksort(int *A ,int low ,int high)
{
    int partition;
    if(high>low)
    {
        partition= partitioning(A,low ,high); // return the index of pivot
        Quicksort(A, low, partition-1);  // left array 
        Quicksort(A, partition+1, high);  // right array
    }
    return 0;
}
int main()
{
    cout<<"enter size of array"<<endl;
    int n;
    cin>>n;
    int A[n];
    cout<<"enter array element"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    Quicksort(A,0,n-1);
    cout<<"sorted array"<<endl;
    print(A ,n);
}


// pivot at last 

/*
#include<bits/stdc++.h>
using namespace std;

int partitioning(int *A ,int low ,int high)
{
    int pivot =A[high];  // pivot at last element
    int i=low-1;      
           
    for(int j =low ;j<=high-1;j++)
    {
        if(A[j]<pivot)
        {
            i++;
            int temp =A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    
    i++;
    int temp = A[i];
    A[i]=pivot;
    A[high]=temp;
    
    // return pivot position means i
    // for next prtitioning in left and right of pivot
    return i;
}
int print(int *A ,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}
int Quicksort(int *A ,int low ,int high)
{
    int partition;
    if(high>low)
    {
        partition= partitioning(A,low ,high); // return the index of pivot
        Quicksort(A, low, partition-1);  // left array 
        Quicksort(A, partition+1, high);  // right array
    }
    return 0;
}
int main()
{
    cout<<"enter size of array"<<endl;
    int n;
    cin>>n;
    int A[n];
    cout<<"enter array element"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    Quicksort(A,0,n-1);
    cout<<"sorted array"<<endl;
    print(A ,n);
}*/

// middle element as pivot 

/*

#include<bits/stdc++.h>
using namespace std;

int print(int *A ,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}

int Quicksort(int *A ,int low ,int high)
{   
    if(low>=high) 
    {
        return 0;
    }
    
   int pivot =A[(low+high)/2];  
    int i=low;      
    int j=high;       
    while(j>=i)
    {
     
      while(A[i]<pivot)  // greater  or equal element check
      {
        i++;
      }
      
      while(A[j]>pivot)  //smaller or equal element check
      {
        j--;
      }
      
      if(j>=i)
      {
          int temp =A[j];
          A[j]=A[i];
          A[i]=temp;
          i++;
          j--;
         
      }

    }
    
    Quicksort(A,low,j);
    Quicksort(A,i,high);
    return 0;
}
int main()
{
    cout<<"enter size of array"<<endl;
    int n;
    cin>>n;
    int A[n];
    cout<<"enter array element"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    Quicksort(A,0,n-1);
    cout<<"sorted array"<<endl;
    print(A ,n);
}

*/