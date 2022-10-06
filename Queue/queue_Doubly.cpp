#include <iostream>
using namespace std;
class Deque
{
public:
    int size;
    int rear;
    int *arr;
};
int insertback(class Deque *q, int value)
{
    if (q->rear == q->size - 1)
    {
        cout << "overflow" << endl;
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = value;
    }
    return 0;
}
int insertfront(class Deque *q, int value)
{
    if (q->rear == q->size - 1)
    {
        cout << "overflow" << endl;
    }
    else
    {
        int x = q->rear;
        for (int i = x + 1; i > 0; i--)
        {
            q->arr[i] = q->arr[i - 1];
        }
        q->arr[0] = value;
        q->rear++;
    }
    return 0;
}
int print(class Deque *q)
{
    if (q->rear == -1)
    {
        cout << "no element to display" << endl;
    }
    else
    {
        for (int i = 0; i <= q->rear; i++)
        {
            cout << q->arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
int deleteback(Deque *q)
{
    if (q->rear == -1)
    {
        cout << "underflow" << endl;
    }
    else
    {
        cout << "dequeued element is :: " << q->arr[q->rear] << endl;
        q->rear--;
    }
    return 0;
}
int deletefront(Deque *q)
{
    if (q->rear == -1)
    {
        cout << "underflow" << endl;
    }
    else
    {
        cout << "dequeued element is :: " << q->arr[0] << endl;
        for (int i = 1; i <= q->rear; i++)
        {
            q->arr[i - 1] = q->arr[i];
        }
        q->rear--;
    }
    return 0;
}
int main()
{
    Deque *q = new Deque();

    cout << "enter size of array" << endl;
    int n;
    cin >> n;
    q->size = n;

    q->rear = -1;
    q->arr = new int();

    while (1)
    {
        int ch;
        cout << "enter choice " << endl;
        cout << "1 for insert at last" << endl;
        cout << "2 for insert at front" << endl;
        cout << "3 for delete from back" << endl;
        cout << "4 for delete from  front" << endl;
        cout << "5 for display the deque" << endl;
        cout << "6 for exit " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            int x;
            cout << "enter element" << endl;
            cin >> x;
            insertback(q, x);
            break;
        }
        case 2:
        {
            int x;
            cout << "enter element" << endl;
            cin >> x;
            insertfront(q, x);
            break;
        }
        case 3:
        {
            deleteback(q);
            break;
        }
        case 4:
        {
            deletefront(q);
            break;
        }
        case 5:
        {
            print(q);
            break;
        }
        case 6:
        {
            cout << "thank you" << endl;
            exit(0);
            break;
        }
        }
    }

    return 0;
}