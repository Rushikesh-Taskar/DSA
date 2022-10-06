#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void maxheap(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        int p = i;
        while (p > 0)
        {
            int q = (p - 1) / 2; // parent node position
            if (arr[q] < arr[p]) // if parent small then swap
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

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void minheap(int arr[],int n)

{
    for (int i = 0; i < n; i++)
    {
        int p = i;
        while (p > 0)
        {
            int q = (p - 1) / 2; // parent node position
            if (arr[q] > arr[p]) // if parent greater then swap
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

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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
    cout<<"max Heap"<<endl;
    maxheap(arr,n);
    cout<<"min Heap"<<endl;
    minheap(arr,n);
    return 0;
}
