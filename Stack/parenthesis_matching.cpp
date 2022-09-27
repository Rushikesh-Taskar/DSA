#include<iostream>
using namespace std;

class stack
{
    public:
    int size;
    int top;
    char *ch;
};
 int isEmpty(class stack *ptr) 
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(class stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char push(class stack *ptr, char a)
{
    if (isFull(ptr))
    {
        cout << "stack overflow can not push : " << a << endl;
        return 0;
    }

    else
    {
        ptr->top++;
        ptr->ch[ptr->top] = a;
        return 0;
    }
}

char pop(class stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "stack is underflow can not pop " << endl;
        
    }
    else
    {
        char val = ptr->ch[ptr->top];
        ptr->top--;
        return val;
    }
}
int paren(char *ptr)
{
    class stack *s;
   s->size=19;
   s->top=-1;
   s->ch=(char*)malloc(sizeof(char));
   for(int i=0;ptr[i]!='\0';i++)
   {
       if(ptr[i] =='(')
       {
           push(s,'(');
       }
       else if(ptr[i]==')')
       {if(isEmpty(s))
       {
           return 0;
       }
       else 
       {
          pop(s);
       }

       }
   }
  if(isEmpty(s))
  {
      return 1;
  }
  else
  {
      return 0;
  }
}
int main()
{
   char *exp = "$($)*(-3(+(67))+)*(";
   if(paren(exp))
   {
       cout<<"parenthesis is matched "<<endl;
   }
   else
   {
       cout<<"parenthesis doed not match"<<endl;
   }
}