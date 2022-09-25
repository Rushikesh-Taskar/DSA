#include <iostream>
#include<cstring>
using namespace std;

class node 
{
    public:
    char *name;
    int salary;
    int age;
    node *next;
};
node *head ,*tail=NULL;
int insert(node *&head ,char *name, int salary ,int age)
{  
    node *newnode = new node();
    newnode->name =name;
    newnode->salary =salary;
    newnode->age=age;
    
    if(head==NULL)
    {
        head = newnode;
        tail= newnode;
        tail->next =NULL;
    }
    else
    {
        tail->next =newnode;
        newnode->next = NULL;
        tail=newnode;
    }
    cout<<"details added successfully"<<endl;
    return 0;
}
int print(node * head)
{   int i=1;
    if(head ==NULL)
    {
        cout<<"please add employee details to display"<<endl;
    }
    else{
    while(head!=NULL)
    {   
        cout<<"\nThe name of the employee "<<i<<" is "<< head->name<<endl;
        cout<<"\nThe salary of the employee "<<i<<" is "<<head->salary<<endl;
        cout<<"\nThe age of the employee "<<i<<" is "<<head->age<<endl;
        head =head->next;
        i++;
    }
    }
    return 0;
}

node *deletedetails(node *head , char *name)
{   
    node *p= head;
    node *q =p->next;
    int a=0;
    
    while(q!=NULL)
    {
        if(strcmp(name,q->name)==0)
        {
           p->next =q->next;
           a++;
           free(q);
           break;
        }
        p=p->next;
        q=q->next;
        
    }
    
    if(a==0)
    {
        cout<<name<<" not found for deletion"<<endl;
    }
    else
    {
        cout<<name <<" details deleted "<<endl;
    }
    
    return head;
}
int search(node *head ,char *name)
{   int a=0;
    while(head!=NULL)
    {   
        if(strcmp(name,head->name)==0)
        {
            cout<<name <<" details found "<<endl;
            cout<<"details of "<<name <<" are"<<endl;
            cout<<"salary is : "<<head->salary<<endl;
            cout<<"age is : "<<head->age<<endl;
            a++;
            break;
        }
        head=head->next;
    }
    if(a==0)
    {   
        int b;
        cout<<name <<" details not found "<<endl;
        cout<<"would you like to add  "<<name <<endl;
        cout<<"enter 1 for add and 0 for continue"<<endl;
        cin>>b;
        if(b==1)
        {
            int age;
            int salary;
            cout<<"enter salary of  "<<name<<endl;
            cin>>salary;
            cout<<"enter age of  "<<name<<endl;
            cin>>age;
            insert(head,name , salary ,age);  
        }
        else
        {
            cout<<"Thank you"<<endl;
        }
       
    }
    return 0;
}
node *modify(node *head ,char *name)
{
   int a=0;
   node *p;
   p=head;
    while(p!=NULL)
    {   
        if(strcmp(name,p->name)==0)
        {   
            int sal;
            int ag;
            cout<<"employee "<<name<<" found "<<endl;
            cout<<"details are"<<endl;
            cout<<"salary is : "<<p->salary<<endl;
            cout<<"age is : "<<p->age<<endl;
            cout<<"enter new salary:"<<endl;
            cin>>sal;
            cout<<"enter new age:"<<endl;
            cin>>ag;
            p->salary =sal;
            p->age=ag;
            a++;
            break;
        }
        p=p->next;
    }
    if(a==0)
    {
        cout<<"employee "<<name<<" not found "<<endl; 
    }
    else
    {
       cout<<"details updated successfully"<<endl;
    }
    return head;
}
int main()
{   cout<<"\n**********************************************************"<<endl;
    cout<<"*       Welcome to employee management System             *"<<endl;
    cout<<"**********************************************************\n"<<endl;

    int f=0;
    do
    {   int g;
        cout<<"enter choice !!!!"<<endl;
        cout<<"1 for add details "<<endl;
        cout<<"2 for delete details "<<endl;
        cout<<"3 for search details "<<endl;
        cout<<"4 for modify details "<<endl;
        cout<<"5 for display details"<<endl;
        cout<<"6 for exit"<<endl;
        cin>>g;
        switch(g)
        {   
            
            case 1:
            {   
                int total;
                cout<<"Enter the number of employee details you would like to add"<<endl;
                cin>>total;
                for(int i =0;i<total;i++)
                {   
                    char *name = new char();
                    int salary;
                    int age;
                    cout<<"enter name of employee "<<i+1<<endl;
                    cin>>name;
                    cout<<"enter salary of " <<name<<endl;
                    cin>>salary;
                    cout<<"enter age of " <<name<<endl;
                    cin>>age;
                    insert(head,name , salary ,age);
                }
                break;
            }
            case 2:
            {   
                char *Name = new char();
                cout<<"enter name of employee to delete the details"<<endl;
                cin>>Name;
                head = deletedetails(head ,Name);
                break;
            }
            
            
            case 3:
            {   
                char *Name = new char();
                cout<<"enter name of employee to search details"<<endl;
                cin>>Name;
               search(head ,Name);
                break;
            }
            
            case 4:
            {  
                 char *Name = new char();
                cout<<"enter name of employee to modify details"<<endl;
                cin>>Name;
                head = modify(head , Name);
                break;
            }
            
            case 5:
            {
                print(head);
                break;
            }
            case 6:
            {
                exit(0);
                break;
            }
            default:
            {
                cout<<"please select correct option "<<endl;
            }
        }
        
    }while(f!=1);

    return 0;
}