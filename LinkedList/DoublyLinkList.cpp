#include <iostream>

using namespace std;
class node 
{
  public:
  int data;
  node *next;
  node *pre;
};

node *head, *tail =NULL;

int insert(int value)
{ 
    node *newnode =new node();
    newnode->data=value;
    if(head==NULL)
    {
        head=newnode;
        head->pre =NULL;
        tail=newnode;
        tail->next=NULL;
    }
    
    else
    {
        tail->next=newnode;
        newnode->next =NULL;
        newnode->pre=tail;
        tail=newnode;
    }
    return 0;
}
int print(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }cout<<endl;
    return 0;
}

node *insertatbegin(node *head ,int value)
{ 
    node *newnode =new node();
    newnode->data =value;
    newnode->pre=NULL;
    newnode->next=head;
    head->pre =newnode;
    head =newnode;
    return head;
}
node *insertatend(node *head ,int value)
{
    node *p=head;
    node *newnode =new node();
    newnode->data =value;
    while(p->next !=NULL)
    {
        p=p->next;
    }
    p->next =newnode;
    newnode->pre =p;
    newnode->next =NULL;
    
    return head;
    
}

node *insertatindex(node *head ,int value ,int index)
{
    node *p=head;
    node *newnode =new node();
    newnode->data =value;
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
    }
    
    newnode->next = p->next;
    newnode->pre= p;
    p->next=newnode;
    p->next->pre =newnode;
    return head;
}
node *deleteatbegin(node *head)
{
    node *p=head;
    p->next->pre=NULL;
    head = p->next;
    free(p);
    return head;
}

node *deleteatend(node *head)
{
    node *p=head;
    node *q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

int main()
{    int n;
    cout<<"enter total no node "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {    
        int x;
        cout<<"enetr value of "<<i+1<<" node"<<endl;
        cin>>x;
        insert(x);
    }
    cout<<"initially"<<endl;
    print(head);
    
    cout<<"after insertion at begin"<<endl;
    head= insertatbegin(head , 67);
    print(head);
   
    cout<<"after insertion at end"<<endl;
    head =insertatend(head ,90);
    print(head);
   
    cout<<"after insertion at index"<<endl;
    head=insertatindex(head ,78 ,2);
    print(head);
    
    cout<<"after deletion at begin"<<endl;
    head=deleteatbegin(head);
    print(head);
    
    cout<<"after deletion at end"<<endl;
    head=deleteatend(head);
    print(head);
    
    cout<<"after deletion at end"<<endl;
    head=deleteatend(head);
    print(head);
    return 0;
}
