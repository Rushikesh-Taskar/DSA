#include <iostream>
using namespace std;

class node
{
  public:
  int data;
  node *next;
};

class node *front=NULL, *rear =NULL;

int enqueue(int value)
{
    node *newnode = new node();
    newnode->data =value;
    newnode->next =NULL;
    
    if(front ==NULL)
    {
        front = newnode;
        rear =newnode;
        
    }
    else
    {
        rear->next =newnode;
        rear =newnode;
    }
}
int dequeue ()
{
    if(front==NULL)
    {
       cout<<"Queue is Empty!!!"<<endl;
    }
    else
    {
        int p;
        node *n= front;
        p= front->data;
        front = n->next;
        free(n);
        cout<<"dequeued element is "<<p<<endl;
    }
}

int display()
{  
    node *p=front;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }cout<<endl;
}
int main()
{
   int choice, value;
    cout<<"\n*** Queue Implementation using Linked List ***\n";
    while(1)
    {
        cout<<"\n****** MENU ******\n";
        cout<<"1. Insert in Queue\n";
        cout<<"2. Delete From Queue\n";
        cout<<"3. Display Queue\n";
       // cout<<"4. Front of the Queue\n";
       // cout<<"5. Size of Queue\n";
        cout<<"6. Exit\n";

        cout<<"Enter your choice:  ";
        cin>>choice;

        switch(choice)
        {
         case 1:
                cout<<"enter the value you want to insert: ";
                cin>>value;
                enqueue(value);
                break;
         case 2:
                dequeue();
                break;
         case 3:
                display();
                break;
         case 6:
                exit(0);
         default:
                cout<<"\nInvalid Selection!!..Select valid number please!!\n";
        };
    }
  
    return 0;
}