#include <iostream>
using namespace std;
class peek
{
public:
    int size;
    int top;
    int *arr;
};

int cheaker(class peek *ptr, int i) 
{
    if (ptr->top - i + 1 < 0)
    {
        cout << "invalid position" << endl;
        return 0;
    }
    else
        cout << "element at " << i << " position is: " << ptr->arr[ptr->top - i + 1]<<endl;
    return 0;
}
int show(class peek *ptr)
{
    cout << "element at last index is:" << ptr->arr[ptr->top] << endl;
    cout << "element at first index  is:" << ptr->arr[0] << endl;
}
int main()
{

    class peek *p = (class peek *)malloc(sizeof(class peek));

    p->size = 5;

    p->top = -1;

    p->arr = (int *)malloc(p->size * sizeof(int));

    p->arr[0] = 9;
    p->top++;
    p->arr[1] = 8;
    p->top++;
    p->arr[2] = 7;
    p->top++;
    p->arr[3] = 5;
    p->top++;
    p->arr[4] = 15;
    p->top++;

    cheaker(p, 1); // first position means size-1 index
    show(p);
    return 0;
}