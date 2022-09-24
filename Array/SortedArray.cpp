#include <iostream>

using namespace std;
bool is_sorted(int A[],int m)
{
    if(m==0 || m==1)
    {
        return true;
    }
    if (A[0]>A[1])
    {
        return false;
    }
    bool is_smaller=is_sorted(A+1,m-1);
    return is_smaller;
}
int main()
{
    int m,n;
    cout<<"enter a size of array:"<<endl;
    cin>>m;
    int A[m];
    cout<<"enter a element:"<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>A[i];
    }
    cout<<is_sorted(A,m)<<endl;

    return 0;
}
