#include <iostream>

using namespace std;

// left child 2*i+1 index starting from 0
// right child 2*i+2 index starting from 0
// parent of any child (index+1)/2 -1

// array to tree
/*
   index 0  1  2  3  4  5  6  7  8
 element 11 12 13 14 15 16 17 18 19
          
          11(0) index root node 
         /  \
    (1) 12  13  (2)
       / \   / \
  (3) 14 15 16 17 (6)
     / \
(7) 18 19 (8) index 

*/
int *tree =new int();
int root(int a)
{
    if(tree[0]==0)
    {
        
         tree[0]=a; 
    }
    else
    {
      cout<<"already have root "<<endl;
    }
    return 0;
}

int left_child(int value,int parent)
{
   int leftchildposition = 2*parent+1;
    tree[leftchildposition]=value;
    return 0;
}

int right_child(int value,int parent)
{
   int rightchildposition = 2*parent+2;  //index starting from zero
    tree[rightchildposition]=value;
    return 0;
}
int print(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<tree[i]<<" ";
    }cout<<endl;
    
    return 0;
}
int preorder(int index, int n)  // root left right
{
    if(index>=0 && index<n)
    {
        cout<<tree[index]<<" ";   //root
        preorder(2*index+1 ,n);  // left child
        preorder(2*index+2 ,n);  // right child 
        /*its create a stack to call recursively function 
        again and again*/
    }
    return 0;
}
int postorder(int index ,int n)  // left right root
{
    if(index>=0 && index<n)
    {
        postorder(2*index+1,n); //left child
        postorder(2*index+2,n);   //right child
        cout<<tree[index]<<" ";   //root
    }
    return 0;
}
int inorder(int index ,int n)  // left root right
{
    if(index>=0 && index<n)
    {
        inorder(2*index+1,n);   // left child
        cout<<tree[index]<<" ";   //root
        inorder(2*index+2,n);   //right child
    }
    return 0;
}
int main()
{
    int n;
    
    cout<<"enter size of array"<<endl;
    cin>>n;
   
    int  A[n];
    cout<<"enter array element"<<endl;
    
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    
    root(A[0]);  // set the root
    
    int k =0;  // for parent 
    
    for(int i=1;i<n;i++)
    {  
        left_child(A[i],k);  // left node
        right_child(A[i+1],k);  // right node
        k++;   // increment of parent 
        i++;
    }
    cout<<"tree"<<endl;
    print(n);
    cout<<"preorder traversal"<<endl;
    preorder(0 ,n);
    cout<<endl;
    cout<<"postorder traversal"<<endl;
    postorder(0,n);
    cout<<endl;
    cout<<"inorder traversal"<<endl;
    inorder(0,n);
    return 0;
}
