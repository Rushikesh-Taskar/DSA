#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(int arr[] ,int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void maxheap(int arr[], int n )
{
    for (int i = 0; i < n; i++)
    {
        int p = i;
        while (p > 0)
        {
            int q = (p - 1) / 2; // parent node position 0 based indexing 
            
            if (arr[q] < arr[p]) // if parent is small then swap
            {
                swap(arr[q], arr[p]);

                p = (p - 1) / 2;
            }

            else
            {
                break;
            }
        }
    }

    
}

void heapsort(int arr[] , int n)
{   
    int ans[n];  // ans array 
    int j=n-1;   
    for(int i=0;i<n;i++)
    {
        maxheap(arr, n-i);  // decrease size one by one 
        ans[j]=arr[0];  // topmost element is greater store it at last position 
        arr[0]=arr[n-i-1]; // copy last element at parent positon 
        j--;   
    }
    
    cout<<"sorted array"<<endl;
    print(ans ,n);
}

int main()
{

    int n;
    cout << "enter total no of array element" << endl;
    cin >> n;
    int arr[n];
    cout << "enter element" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    heapsort(arr,n);
    return 0;
}