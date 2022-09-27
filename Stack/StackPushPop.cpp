#include <iostream>
using namespace std;
class stack
{
public:
    int size;
    int top;
    int *arr;
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

int push(class stack *ptr, int a)
{
    if (isFull(ptr))
    {
        cout << "stack overflow  : " << a << endl;
        
    }

    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = a;
        
    }
    return 0;
}

int pop(class stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "stack  underflow  " << endl;
        
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
    return 0;
}
int show(stack *s)
{
    int i;
    for(i=s->top;i>=0;i--)
    {   
        cout<<s->arr[i]<<" ";
        
    }cout<<endl;
    
    return 0;
}
int main()
{
    class stack *s = new stack();
    s->top = -1;
    s->arr = new int();
    int p=0;
    int k;
    cout<<"eneter size of stack "<<endl;
    cin>>k;
    s->size =k;
    do
    {
        cout<<"enter 1 for push the element in stack"<<endl;
        cout<<"enter 2 for pop the element from stack"<<endl;
        cout<<"enter 3 for display the stack"<<endl;
        cout<<"enter 4 for check empty and full condition"<<endl;
        cout<<"enter 5 for exit "<<endl;
        int g;
        cin>>g;
        switch(g)
        {
            case 1:
            {   int d;
              cout<<"enter element "<<endl;
              cin>>d;
              push(s,d);
                break;
            }
            case 2:
            {   
                cout << "poped element is: " << pop(s) << endl;
                break;
            }
            case 3:
            {   
                show(s);
                break;
            }
            case 4:
            {   cout << " stack Empty: " << isEmpty(s) << endl;
                cout << " stack Full: " << isFull(s) << endl;
                break;
            }
            case 5:
            {   
                exit(0);
                break;
            }
        }
    } while (p!=1);
    /*
    cout << "before pushing Empty:" << isEmpty(s) << endl;
    cout << "before pushing Full:" << isFull(s) << endl;

    push(s, 24);
    push(s, 34);
    push(s, 44);      // pushining the element inside the stack 
    push(s, 74);
    push(s, 84);
    push(s, 94);
    
    push(s, 56);         // can not push element 
    push(s, 89);

    cout << "after pushing Empty:" << isEmpty(s) << endl;
    cout << "after pushing Full:" << isFull(s) << endl;
 

    cout << "poped element is: " << pop(s) << endl;      // popining thr element 
    cout << "poped element is: " << pop(s) << endl;
    cout << "poped element is: " << pop(s) << endl;       // last in first out
    cout << "poped element is: " << pop(s) << endl;
    cout << "poped element is: " << pop(s) << endl;
    cout << "poped element is: " << pop(s) << endl;

    pop(s) ;                                            // can not pop element 
    

    cout << "after poping Empty:" << isEmpty(s) << endl;
    cout << "after poping Full:" << isFull(s) << endl;    
 */
    return 0;

}