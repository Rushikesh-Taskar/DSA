#include<iostream>
using namespace std;

/*

In this case, when we insert the elements in the stack (stack1)
then the elements are added on the top of the stack so 
it takes O(1) time.

In case of dequeue operation, we need to consider two stacks 
named as Stack1 and Stack2. First, we insert the elements 
in the Stack1 and then we remove all the elements from the 
Stack1. Once all the elements are popped from the Stack1 then 
they are added in the Stack2. The topmost element would 
be popped out from the Stack2 and then all the elements 
from the Stack2 are moved back to Stack1. Here, dequeue 
operation is 
performed two times on the data so time complexity is O(n).
*/
class stack1
{
  public:
  int size1;
  int top1;
  int *arr1;
};
class stack2
{
  public:
  int size2;
  int top2;
  int *arr2;
};

int enqueue(stack1 *s1,int value)
{
    if(s1->top1 == s1->size1-1)
    {
        cout<<"queue is full"<<endl;
    }
    else
    {
      s1->top1++;
      s1->arr1[s1->top1]=value;
    }
    return 0;
}
int dequeue(stack1 *s1 ,stack2 *s2)
{
    if(s1->top1 == -1)
    {
        cout<<"queue is is empty"<<endl;
    }
    else
    {
        while(s1->top1!=-1)
        {
            s2->top2++;
            s2->arr2[s2->top2] = s1->arr1[s1->top1];
            s1->top1--;
        }
        cout<<"dequeued element is "<<s2->arr2[s2->top2]<<endl;
        s2->top2--;
        while(s2->top2!=-1)
        {
            s1->top1++;
            s1->arr1[s1->top1] = s2->arr2[s2->top2];
            s2->top2--;
        }
    }
   return 0;
}
int print(stack1 *s1)
{
    for(int i=0;i<=s1->top1;i++)
    {
        cout<<s1->arr1[i]<<" ";
    }cout<<endl;
    return 0;
}
int main()
{
   stack1 *s1= new stack1();
   stack2 *s2= new stack2();
    
    cout<<"enter size of queue"<<endl;
    int n;
    cin>>n;

    s1->size1 =n;
    s2->size2 =n;

    s1->top1 =-1;
    s2->top2 =-1;

    s1->arr1 =new int();
    s2->arr2 =new int();
   

   char y;
     
     do
     {   cout<<"enter choice"<<endl;
         cout<<"1 for enqueue operation "<<endl;
         cout<<"2 for dequeue operation "<<endl;
         cout<<"3 for display queue"<<endl;
         int choice;
         cin>>choice;

        switch(choice)
        {
            case 1:
            {    
               int x;
               cout<<"enter element element "<<endl;
               cin>>x;
               enqueue(s1 ,x);
                break;
            }
            case 2:
            {
               dequeue(s1,s2);
               break;
            }
            case 3:
            {   
                print(s1);
                break;
            }
            default :
            {   
                cout<<"please enter correct choice"<<endl;
                break;
            }
            
        }
        cout<<"do you want to continue (y/n)"<<endl;
        cin>>y;
     }while(y=='y');
    
    /*enqueue(s1 ,71);
    enqueue(s1 ,72);
    enqueue(s1 ,73);
    enqueue(s1 ,74);
    enqueue(s1 ,75);
    enqueue(s1 ,76);
    dequeue(s1,s2);
    print(s1);*/

}