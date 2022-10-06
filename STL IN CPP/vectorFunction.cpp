#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int vecfun( vector<int>A)
{
    A.push_back(30);
}
int vecfunref( vector<int>&A)
{
    A.push_back(30);
    cout<<"printing by using function"<<endl;
    for(auto i:A)
    {
        cout<<i<<endl;
    }
}
int main()
{
    vector<int> A;
    A.push_back(10);
    A.push_back(20);
    //vecfun(A);  // 30 not added its normal
     vecfunref(A);  //30 will add its refrance to vector 
      cout<<"printing by using main function"<<endl;
    for(auto i:A)
    {
        cout<<i<<endl;
    }

}