#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool isodd(int i) 
{ 
  if(i%2==1)
  {
    return true;
  }
}
int main()
{
    //vector<int> A(4); //vector of type int of size 4
   //vector<int> A={1,2,3,4}; //vector with element

   /*
   vector<int>A;
   int n;
   cout<<"enter size"<<endl;
   cin>>n;
   cout<<"enter element"<<endl;
   for(int i=0;i<n;i++) 
   {
       int a;
       cin>>a;
       A.push_back(a);
   }
   //for print element
   /*
   for(int i=0;i<n;i++) 
   {
       cout<<A[i]<<endl;
   }

   for(auto i=A.begin();i!=A.end();i++)
   {
       cout<<*i<<endl;   //here i is pointer 
   }
   )
    //for each loop
    for(auto i:A)
    {
        cout<<i<<" ";
    }*/

    //2D vector or copy with different data type


    vector<int>B;      //int data type
    B.push_back(1);
    B.push_back(2);
    vector<int>F;      //int data type
    F.push_back(3);
    F.push_back(4);
    F.push_back(5);
    //F.erase(F.begin() ,F.begin()+2);
   //cout<<F.at(2)<<endl;
   //int i=lower_bound(F.begin(),F.end(),2)-F.begin();
   // cout<<i<<endl;
   int n= count_if(F.begin(), F.end() ,isodd);
   copy_if(F.begin(),F.end(),B.begin(),isodd);    //not take first elment of vector B 
   B.push_back(3);
   cout<<"B vector after copy operation"<<endl;
   for(auto i:B)
   {
       cout<<i<<" ";
   }cout<<endl;
   cout<<"odd no of F vector is "<<n<<endl;
    vector <float> C;   //float data type 
    C.push_back(34.5);
    C.push_back(45);
    C.push_back(23.77);

    vector <string> D;   //string data type 
    D.push_back("hii");
    D.push_back("hello");

    vector<char> E;     //char data type
    E.push_back('a');
    E.push_back('b');
    E.push_back('c');
    E.push_back('d');
     
     //following not possible because B is vector and Arr also for that
     //we need to create Arr as 2D
    //vector<int> Arr;
    //Arr.push_back(B);    

    //2D
    vector<vector<int>>Arr;
    Arr.push_back(B);
    Arr.push_back(B);
    Arr.push_back(F);
    cout<<Arr[1][1]<<endl;
    cout<<Arr[1][2]<<endl;
    cout<<Arr[2][2]<<endl;
    //each element of 2D vector will
    for(auto i :Arr)   //i is vector
    {
       for(auto j:i)
       {
           cout<<j<<" ";
       }
    }

    /*
    Arr look like  2D
          0  1  2
    0(B)  1  2  garbage
    1(B)  1  2  garbage
    2(F)  3  4  5
    */
    
    

}