#include <iostream>
using namespace std;

class stack
{
public:
    int size;
    int top;
    char *ch;
};
char isFull(class stack *ptr)
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
char isEmpty(class stack *ptr)
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
char pop(class stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "can not pop empty stack" << endl;
    }
    else
    {
        char val = ptr->ch[ptr->top];
        ptr->top--;
        return val;
    }
}
char push(class stack *ptr, char a)
{
    if (isFull(ptr))
    {
        cout << "can't push stack is full" << endl;
    }
    else
    {
        ptr->top++;
        ptr->ch[ptr->top] = a;
        return 0;
    }
}
char top(class stack *ptr)
{
    return ptr->ch[ptr->top];
}
int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    else if (a == '[' && b == ']')
    {
        return 1;
    }
    else if (a == '{' && b == '}')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int mulpar(char *ptr)
{
    class stack *s;
    s->size = 100;
    s->top = -1;
    s->ch = (char *)malloc(sizeof(char));
    char popped_ch;
    for (int i = 0; ptr[i] != '\0'; i++)
    {
        if (ptr[i] == '(' || ptr[i] == '[' || ptr[i] == '{')
        {
            push(s, ptr[i]);
        }
        else if (ptr[i] == ')' || ptr[i] == ']' || ptr[i] == '}')
        {
            if (isEmpty(s))
            {
                return 0;
            }

            popped_ch = pop(s);
            if (!match(popped_ch, ptr[i]))
            {
                return 0;
            }
        }
    }
    if (isEmpty(s))
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
    char *exp = "{3+{3+5+[4*6=(6-7*9)]}";
    if (mulpar(exp))
    {
        cout << "parenthesis is matched " << endl;
    }
    else
    {
        cout << "parenthesis doed not match" << endl;
    }
}
