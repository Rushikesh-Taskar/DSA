#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
class myarray
{
    public:
    int total_size;
    int used_size;
    int *ptr;
    int creatarray(myarray *a,int tsize, int usize)
    {
        a->total_size=tsize;
        a->used_size=usize;
        a->ptr=(int*)malloc(tsize * sizeof(int));
         return 0;
    }
    int set (myarray *a )
    {    int n;
        for(int i=0; i<used_size ; i++)
        {   cout<<"enter a no"<<" ";
             cin>>n;
             a->ptr[i]=n;
        }
    }
    int show (myarray *a )
    {   
        for(int i=0; i<used_size ; i++)
        {
             cout<<a->ptr[i]<<" ";
             
        }
    }
    
};
int main()
{    int m;
   myarray mark;
   mark.creatarray(&mark ,10,5);
   mark.set(&mark);
   mark.show(&mark);
   
}