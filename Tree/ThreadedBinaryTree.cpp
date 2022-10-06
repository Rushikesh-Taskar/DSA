#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    // Thread right , left for helping to determine connection
    int Lthread; // for parent to child or root to ancestor connection
    int Rthread;
    Node *left, *right;
    Node(int value)
    {
        data = value;
        Lthread = 1; // 1 means we can not  move
        Rthread = 1;
    }
};

Node *root = NULL;

Node *create(Node *root, int value)
{
    Node *parent = NULL;
    Node *cur = root;
    Node *newnode = new Node(value);
    if (root == NULL) // base case
    {
        root = newnode;
        newnode->left == NULL;
        newnode->right == NULL;
        return root;
    }

    while (true)
    {
        parent = cur; // needed in future for connection

        if (cur->data > value) // move to left
        {
            // Lthread is 0 means child is present in left we can move
            // to left of current parent

            if (cur->Lthread == 0)
            {
                cur = cur->left;
            }
            else // Lthread is 1 insertion condition
            {

                newnode->left = parent->left;
                newnode->right = parent;
                parent->Lthread = 0;
                parent->left = newnode;
                break;
            }
        }

        else // move right
        {
            if (cur->Rthread == 0)
            {
                cur = cur->right;
            }
            else // Rthread is 1 insertion condition
            {

                newnode->left = parent;
                newnode->right = parent->right;
                parent->Rthread = 0;
                parent->right = newnode;
                break;
            }
        }
    }

    return root;
}
Node *inordersuccessor(Node *cur)
{
    // base case
    if (cur->Rthread == 1)
    {
        return cur->right;
    }
    cur = cur->right;
    while (cur->Lthread == 0)
    {
        cur = cur->left;
    }
    return cur;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        cout << "tree is empty" << endl;
        return;
    }

    Node *cur = root;
    // find leftmost node
    while (cur->Lthread == 0) // we can move to left
    {
        cur = cur->left;
    }

    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = inordersuccessor(cur);
    }
    return;
}

int main()
{
    int n;
    int choice;
    cout << "enter total no of node " << endl;
    cin >> n;
    cout << "enter value of node " << endl;
    while (n--)
    {
        int x;
        cin >> x;
        root = create(root, x);
    }
    cout << "inorder travesal of tree" << endl;
    inorder(root);
    return 0;
}

/*#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
   public:
   int data;
   // Thread right , left for helping to determine connection
   int Lthread;  // for parent to child or root to ancestor connection
   int Rthread;
   Node *left ,*right;
   Node(int value)
   {
       data =value;
       Lthread=1;  // 1 means we can not  move
       Rthread=1;
   }

};

Node *root =NULL;

Node* create(Node *root ,int value)
{
   Node *parent=NULL;
   Node *cur =root;

   Node *newnode = new Node(value);

   if(root==NULL);  // base case
   {
       root =newnode;
       newnode->left==NULL;
       newnode->right==NULL;
       return root;    // stop function call
   }

   while(true)
   {
       parent =cur;  // needed in future for connection

       if(cur->data > value) // move to left
       {
           // Lthread is 0 means child is present in left we can move
          //to left of current parent

        if(cur->Lthread==0)
        {
            cur =cur->left;
        }
        else   // Lthread is 1 insertion condition
        {
         newnode->left = parent->left;
          newnode->right = parent;
          parent->Lthread=0;
          parent->left=newnode;
            break;
        }
       }

       else    // move right
       {
        if(cur->Rthread==0)
        {
            cur =cur->right;
        }
        else   // Rthread is 1 insertion condition
        {

        newnode->left = parent;
          newnode->right = parent->right;
          parent->Rthread=0;
          parent->right=newnode;

            break;
        }
       }
   }

  return root ;
}
Node *inordersuccessor(Node *cur)
{
    // base case
   if(cur->Rthread ==1)
   {
       return cur->right;
   }
    cur = cur->right;
    while (cur->Lthread ==0)
    {
        cur = cur->left;
    }
    return cur;
}

void inorder(Node* root)
{
    if(root == NULL)
    {
        cout<<"tree is empty"<<endl;
        return;
    }

   Node* cur =root;
   // find leftmost node
   while(cur->Lthread==0)  // we can move to left
   {
        cur =cur->left;
   }

   while(cur!=NULL)
   {
       cout<<cur->data<<" ";
       cur = inordersuccessor(cur);
   }
   return;
}


int main()
{
    int n;
    int choice;
    cout << "enter total no of node " << endl;
    cin >> n;
    cout << "enter value of node " << endl;
    while (n--)
    {
        int x;
        cin >> x;
        root =create(root , x);
    }
    inorder(root);
    return 0;
}*/