// own logic for infix to postfix 
// but not working for ( ) due to some problem
/* #include<iostream>
#include <bits/stdc++.h>
using namespace std;

class stac
{   public:
    int size;
    int top;
    char *arr;
};

int stacTop(class stac* sp)
{
    return sp->arr[sp->top];
}

int isEmpty(class stac *ptr)
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

int isFull(class stac *ptr)
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

void push(class stac* ptr, char val)
{
    if(isFull(ptr))
    {
        cout<<"stac Overflow! Cannot push to the stac:"<< val<<endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(class stac* ptr)
{
    if(isEmpty(ptr))
    {
        cout<<"stac Underflow! Cannot pop from the stac"<<endl;
        return -1;
    }
    else
    {
        //char val = ptr->arr[ptr->top];
        ptr->top--;
        return 0;
        //return val;
    }
    
}

int precedence(char ch)
{   
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}

int isOperator(char ch)
{
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
        return 1;
    else
        return 0;
}

void infixToPostfix(char* infix)
{
    class stac* sp = new stac();
    sp->size = 20; 
    sp->top = -1;
    sp->arr = new char();
    string postfix;
    int i=0;     // Track infix traversal
    int j=0;     // Track postfix addition 
    while (infix[i]!='\0')
    {   
        if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= '0' && infix[i] <= '9'))
        {
            postfix += infix[i];
            i++;
        }
        else if(infix[i]=='(')
        {
            push(sp, '(');
            i++;
        }

        else if(infix[i]==')')
        {
           while(sp->arr[sp->top]!='(')
           {
                postfix += sp->arr[sp->top];
                pop(sp);
           }
           pop(sp);
        }

        else
        {
            if(precedence(infix[i])> precedence(stacTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix += sp->arr[sp->top];
                pop(sp);
                i--;
            }
        }
    }
    while (!isEmpty(sp))    
    {
        postfix += sp->arr[sp->top];
        pop(sp);
        
    }
    //postfix[j] = '\0';
    cout<<"postfix is "<<postfix <<endl;
}
int main()
{
    char* infix = new char();
    cout<<"enter infix expression to convert into postfix"<<endl;
    cin>>infix;
    infixToPostfix(infix);
    
    return 0;
}*/

// infix to postfix 

/*
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int precedence(char ch)
{    
    if(ch=='^')
       return 4;
    else if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}

void solve(string s)
{
    stack<char> sp;
    string post;
    for(int i=0;i<s.size();i++)
    {   
        char c =s[i];
        if(c>='a'&& c<='z' || c>='A'&& c<='Z' || c-'0'>=0 && c-'0'<=9)
        {
            post =post+c;
        }
        else if(c=='(')
        {
            sp.push(c);
        }
        else if(c==')')
        {
            while(sp.top() !='(')
            {
                post = post+sp.top();
                sp.pop();
            }
            sp.pop();
        }
        
        else 
        {   
            if (sp.empty())
            {
                sp.push(c);
            }
            else if( precedence(c)>precedence(sp.top()))
            {
                sp.push(c);
            }
            else if(!sp.empty())
            {
                post = post+sp.top();
                sp.pop();
                i--;
            }
        }
    }
    while(!sp.empty())
    {
         post = post+sp.top();
         sp.pop();
    }
    
    cout<<"postfix expression of "<<s<<" is "<<post;
}
int main()
{
   string s;
   cout<<"enter an expression to convert it into postfix"<<endl;
   cin>>s;
   solve(s);

    return 0;
}*/




// infix to prefix 




#include<bits/stdc++.h>
using namespace std;

int precedence(char ch)
{    
    if(ch=='^')
       return 4;
    else if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}

void solve(string s)
{
    stack<char> sp;
    string post;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++)
    {
         if (s[i] == '(')
         {
            s[i] = ')';
         }
        else if (s[i] == ')') 
        {
            s[i] = '(';
        }
    }
    
    for(int i=0;i<s.size();i++)
    {   
        //cout<<post<<endl;
        char c =s[i];

        if(c>='a'&& c<='z' || c>='A'&& c<='Z' || c-'0'>=0 && c-'0'<=9)
        {
            post =post+c;
            
        }
        else if(c=='(')
        {
            sp.push(c);
        }
        else if(c==')')
        {
            while(sp.top() !='(')
            {
                post = post+sp.top();
                sp.pop();
            }
            sp.pop();
        }
        
        else 
        {   
            if (sp.empty())
            {
                sp.push(c);
            }
            else if( precedence(c)>precedence(sp.top()))
            {
                sp.push(c);
            }
            else if(!sp.empty())
            {
                post = post+sp.top();
                sp.pop();
                i--;
            }
        }
    }
    while(!sp.empty())
    {
         post = post+sp.top();
         sp.pop();
    }
    reverse(post.begin(),post.end());

    cout<<"prefix expression of "<<s<<" is "<<post;
}
int main()
{
   string s;
   cout<<"enter an expression to convert it into prefix"<<endl;
   cin>>s;
   solve(s);

    return 0;
}
