#include <iostream>
using namespace std;
class list
{
public:
    int data;
    class list *next;
};

list *head = NULL, *tail = NULL;
int insert(int data)
{
    list *newnode = new list();
    newnode->data = data;
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
    }
    return 0;
}
void show(class list *head)
{
    class list *p = head;
    // cout<<p->data<<" ";
    // p=p->next;
    do
    {
        cout << p->data << " ";
        p = p->next; // do while loop instade of while loop
    } while (p != head);
    cout<<endl;
}
list *insertatbegin(list *head ,int data)
{

    list * p=head->next;
    list *newnode =new list();
    newnode->data =data;
    while(p->next !=head)
    {
        p =p->next;
    }
    newnode->next =p->next;
    p->next = newnode;
    head=newnode;
    return head;
}

list *insertatend(list *head ,int data)
{

    list * p=head;
    list *newnode =new list();
    newnode->data =data;
    while(p->next !=head)
    {
        p =p->next;
    }
    newnode->next =p->next;
    p->next = newnode;
    
    return head;
}
list *insertatmid(list *head ,int data ,int index)
{

    list * p=head;
    list *newnode =new list();
    newnode->data =data;
    int i=0;
    while(i<index-1)
    {
        p =p->next;
        i++;
    }
    newnode->next =p->next;
    p->next = newnode;
    
    return head;
}
list *deleteatbegin(list *head )
{

    list * p=head;
    list *q=head->next;
    while(p->next!=head)
    {
        p =p->next;
        q= q->next;
    }
    p->next = q->next;
    head =q->next;
    free(q);
    return head;
}

list *deleteatend(list *head )
{

    list * p=head;
    list *q=head->next;
    while(q->next!=head)
    {
        p =p->next;
        q=q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

int main()
{
    int n;
    cout << "how many node you wan't" << endl;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int x;
        cout<<"enetr data of node "<<i+1<<endl;
        cin>>x;
        insert(x);
    }
    int g=0;
    do
    {  int p;
       cout<<"enter choice"<<endl;
       cout<<"1 for insert at begin"<<endl;
       cout<<"2 for insert at end"<<endl;
       cout<<"7 for insert at mid"<<endl;
       cout<<"3 for delete at begin"<<endl;
       cout<<"4 for delete at end"<<endl;
       cout<<"6 for display"<<endl;
       cout<<"5 for exit"<<endl;
       cin>>p; 

       switch(p)
       {
           case 1:
           {
               int x;
               cout<<"enter value to insert"<<endl;
               cin>>x;
               head =insertatbegin(head ,x);
             break;  
           }
           case 2:
           {
               int x;
               cout<<"enter value to insert"<<endl;
               cin>>x;
               head =insertatend(head ,x);
               break;
           }
           case 3:
           {
               head=deleteatbegin(head);
               break;
           }
           case 4:
           {
                head=deleteatend(head);
                break;
           }
           case 6:
           {
               show(head);
               break;
           }
           case 7:
           {
               int x;
               cout<<"enter value to insert"<<endl;
               cin>>x;
               int y;
               cout<<"enter index at which insert node"<<endl;
               cin>>y;
               head =insertatmid(head ,x ,y);
               break;
           }
           case 5:
           {
               exit(0);
               break;
           }
       }
       
    } while (g!=1);
    
    
    
    return 0;
}