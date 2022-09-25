//evaluation of polynomial

/*#include <iostream>
#include<cmath>
using namespace std;

//evaluation by circular linkedlist 
class poly
{
public:
    int coeff;
    int expo;
    poly *next;
};
poly *head=NULL, *tail = NULL;
int insert(int coeff, int expo)
{
    poly *newnode = new poly();

    newnode->coeff = coeff;
    newnode->expo = expo;
    //newnode->next = NULL;          //for singly linked list
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    
    else
    {
        tail->next = newnode;
        tail = newnode;
        tail->next=head;           //not in singly linked list
    }
    return 0;
}

int display(poly *p)
{
    do
    {
        cout<<p->coeff<<"(x^"<<p->expo<<")+";
        p=p->next;
    }while(p->next!=head);
    cout<<p->coeff<<"(x^"<<p->expo<<")"<<endl;
    return 0;
}
int evaluation(poly *p ,int x)
{
    int sum=0;
    do
    {
      sum+=p->coeff*pow(x,p->expo);
      p=p->next;
    }while(p!=head);
    cout<<"evaluation of polynomial is :"<<sum<<endl;
    return 0;
}
int main()
{
    int a, b;
    cout << "enter total number of term in polynomial" << endl;
    cin >> a;
    cout << "enter term in descending order" << endl;
    for (int i = 0; i < a; i++)
    {
        int x, y;
        cout << "enter coefficient of " << i + 1 << " term" << endl;
        cin >> x;
        cout << "enter exponential of " << i + 1 << " term" << endl;
        cin >> y;
        insert(x, y);
    }
    cout<<"entered polynomial is "<<endl;
    display(head);
    int eval;
    cout<<"enter no for polynomial evaluation "<<endl;
    cin>>eval;
    evaluation(head ,eval);

}*/

//for addition and multiplication by doubly linked list


#include <iostream>

using namespace std;

class poly
{
public:
    int coeff;
    int expo;
    poly *previous;
    poly *next;
};

poly *head,*second, *mul ,*tail=NULL,*tail2=NULL,*tail3=NULL;

int insert(int coeff ,int expo )
{   
    poly *newnode=new poly();
    newnode->coeff=coeff;
    newnode->expo=expo;
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
        head->previous=NULL;
        tail->next=NULL;
    }
    else
    {
        tail->next=newnode;
        newnode->previous=tail;
        tail=newnode;
        tail->next=NULL;
    }
    return 0;
}

int insert2(int coeff ,int expo )
{
    poly *newnode=new poly();
    newnode->coeff=coeff;
    newnode->expo=expo;
    if(second==NULL)
    {
        second=newnode;
        tail2=newnode;
        second->previous=NULL;
        tail2->next=NULL;
    }
    else
    {
        tail2->next=newnode;
        newnode->previous=tail2;
        tail2=newnode;
        tail2->next=NULL;
    }
    return 0;
}
int insert3(int coeff ,int expo)
{
    poly *newnode=new poly();
    newnode->coeff=coeff;
    newnode->expo=expo;
    
    if(mul==NULL)
    {
        mul =newnode;
        tail3=newnode;
        mul->previous = NULL;
        tail3->next=NULL;
    }
    else
    {
        tail3->next =newnode;
        newnode->previous=tail3;
        tail3 = newnode;
        tail3->next =NULL;
    }
    return 0;
}
int print(poly *head)
{   
    while(head->next!=NULL)
    {
        cout<<head->coeff<<"(x^"<<head->expo<<")+";
        head=head->next;
        
    }
    cout<<head->coeff<<"(x^"<<head->expo<<")"<<endl;
    return 0;
}

int add(poly *head ,poly *second)
{
    while(head->next!=NULL)
    {
        cout<<head->coeff+second->coeff<<"(x^"<<head->expo<<")+";
        head=head->next;
        second=second->next;
    }
     cout<<head->coeff+second->coeff<<"(x^"<<head->expo<<")"<<endl;
    return 0;
}
int arrange(poly *mul)
{
while(mul!=NULL)
     {   
         poly *q=mul;
         poly *p=mul->next;
         while(p!=NULL)
         {
             if(mul->expo==p->expo)
             {
                mul->coeff = mul->coeff+p->coeff;

                q->next=p->next;
                p->next->previous=q;
                poly *del=p;
                p=p->next;
                free(del);
             }
             else
             {
             p=p->next;
             q=q->next;
             }
         }
         mul=mul->next;
     }
     return 0;
}
int multiplication(poly *head , poly *second)
{
     while(head!=NULL)
     {  poly *p =second;
        while(p!=NULL)
        {   
            int a=head->coeff*p->coeff;
            int b= head->expo+p->expo;
            insert3(a,b);
            p = p->next;
        }
        head =head->next;
     }  
    arrange(mul);
    print(mul);
    return 0;
}

int main()
{
   int n;
   cout<<"enter total no of term of first polynomial "<<endl;
   cin>>n;
   cout<<"enter term in descending order"<<endl;
   for(int i=0;i<n;i++)
   {   int x,y;
       cout<<"enter coefficient of "<<i+1<<" term"<<endl;
       cin>>x;
       cout<<"enter exponent of "<<i+1<<" term"<<endl;
       cin>>y;
       insert(x,y);
   }
   cout<<"first polynomial is :";
   print(head);
   
   int m;
   cout<<"enter total no of term of second polynomial"<<endl;
   cin>>m;
   cout<<"enter term in descending order"<<endl;
   for(int i=0;i<m;i++)
   {   int x,y;
       cout<<"enter coefficient of "<<i+1<<" term"<<endl;
       cin>>x;
       cout<<"enter exponent of "<<i+1<<" term"<<endl;
       cin>>y;
       insert2(x,y);
   }
   cout<<"second polynomial is :";
   print(second);
   
   cout<<"addition of polynomial is "<<endl;
   add(head ,second);
   cout<<"multiplication of polynomial is "<<endl;
   multiplication(head ,second);
    return 0;
}
