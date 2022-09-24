#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int i;
int search_ele(int A[], int n)
{
    int key;
    cout << "enter a element for searching in array" << endl;
    cin >> key;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == key)
        {
            cout << "key (element) is present at "
                 << " " << i << " "
                 << "index" << endl;
        }
    }
}
bool search_sum(int A[], int n)
{
    int sum;
    
    cout<<"enter sum to find two element in ";
    cout<<"array whose sum is equal to entered sum"<<endl;
    cin>>sum;
    sort(A,A+n);   //sort the array
    int low=0;
    int high=n-1;
    while(low<high)
    {   
        if(A[low]+A[high]==sum)
        {
            cout<<"sum is present at"<<low<<" and "<<high<<"index element"<<endl;
            low++;
        }
        else if(A[low]+A[high]<sum)
        {
               low++;
        }
        else if (A[low]+A[high]>sum)
        {
             high--;
        }
    }

}
int main()
{
    int n, i;
    cout << "enter a size of array" << endl;
    cin >> n;
    int A[n];
    cout << "enter " << n << "element" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    //search_ele(A,n);    //searching the elements
    search_sum(A,n);      //search sum for two no

    return 0;
}
