#include <iostream>
using namespace std;
//#include <stdlib.h>

int main()
{
    /*
    //use of malloc()

    int *ptr;                    // int A[50]
    int n;
    
    cout<<"enter size of array :"<<endl;
    cin>>n;
    ptr = (int *)malloc(n*sizeof(int));
   for (int i = 0; i < n; i++)
    {
        cout << "enter value no " << i << "  of this array" << endl;
        cin >> ptr[i];
    }
    cout << "entered value are: " << endl;
    for (int i = 0; i < n; i++)

    {
        cout << ptr[i] << " ";
    }*/

    //use of calloc()

    int *ptr;
    int n;

    cout << "enter size of array :" << endl;
    cin >> n;
    ptr = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        cout << "enter value no " << i << "  of this array" << endl;
        cin >> ptr[i];
    }
    cout << "entered value are: " << endl;
    for (int i = 0; i < n; i++)

    {
        cout << ptr[i] << " ";
    }
    cout << endl;

    // use of realloc()

    cout << "enter size of new array :" << endl;
    cin >> n;
    ptr = (int *)realloc(ptr, n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        cout << "enter value no " << i << "  of this array" << endl;
        cin >> ptr[i];
    }
    cout << "entered value are: " << endl;
    for (int i = 0; i < n; i++)

    {
        cout << ptr[i] << " ";
    }

    free(ptr); //memory become free inside heap
}