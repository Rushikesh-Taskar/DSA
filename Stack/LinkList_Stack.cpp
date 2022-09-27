#include <iostream>
using namespace std;

class stack
{
public:
    int data;
    class stack *next;
};
class stack *top = NULL;  // top decleration in globally

int isFull(class stack *top)
{
    class stack *n = (class stack *)malloc(sizeof(class stack));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(class stack *top)
{

    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
class stack *push(class stack **top, int x)  //insert at begin
{
    if (isFull(*top))
    {
        cout << "stack is full " << endl;
        
    }
    else
    {
        class stack *n = new stack();
        n->data = x;
        n->next = *top;
        *top = n;
        
    }
    return 0;
}
int pop(class stack **top)   //delete at begin
{
    if (isEmpty(*top))
    {
        cout << "stack  underflow " << endl;
    }
    else
    {
        class stack *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
    return 0;
}

int linklisttraversal(class stack *top)  // print the linked-list (stack)
{
    while (top != NULL)
    {
        cout << top->data <<" ";
        top = top->next;
    }cout<<endl;
    return 0;
}

int main()
{
    int p=0;
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
              push(&top,d);
                break;
            }
            case 2:
            {   
                cout << "poped element is: " << pop(&top) << endl;
                break;
            }
            case 3:
            {   
                linklisttraversal(top);
                break;
            }
            case 4:
            {   cout << " stack Empty: " << isEmpty(top) << endl;
                cout << " stack Full: " << isFull(top) << endl;
                break;
            }
            case 5:
            {   
                exit(0);
                break;
            }
        }
    } while (p!=1);


   //old code 

    /*top = push(top, 6);
    top = push(top, 7);
    top = push(top, 67);
    top = push(top, 87);        // reversed order because insertion at begin

    linklisttraversal(top);

    cout << "popped element is: " << pop(&top) << endl;
    cout << "popped element is: " << pop(&top) << endl;       // as a address 

    linklisttraversal(top);

    cout<<"top element of the stack is: "<<top->data << endl;*/
   
    return 0;
}