#include <iostream>
using namespace std;

class cir_queue
{
public:
    int size;
    int f; // front pointer  dequeue
    int r; // back pointer (rear)   enqueue
    int *arr;
};
int isFull(cir_queue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(class cir_queue *q)
{
    if (q->f == -1 && q->r == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int enqueue(class cir_queue *q, int value)
{

    if (q->f == -1 && q->r == -1)
    {
        q->f = 0;
        q->r = 0;
        q->arr[q->r] = value;
        cout << "enqueued element is " << value << endl;
    }
    else if ((q->r + 1) % q->size == q->f)
    {
        cout << "can't enqueue queue is full" << endl;
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = value;
        cout << "enqueued element is " << value << endl;
        return 0;
    }
    return 0;
}
int dequeue(class cir_queue *q)
{
    if (q->r == -1 && q->f == -1)
    {
        cout << "can't dequeue queue is Empty" << endl;
    }
    else if (q->r == q->f)
    {
        int del;
        del = q->arr[q->f];
        cout << "dequeued element is:" << del << endl;
        q->f = -1;
        q->r = -1;
    }
    else
    {
        int del;
        del = q->arr[q->f];
        cout << "dequeued element is:" << del << endl;
        q->f = (q->f + 1) % q->size;
    }
    return 0;
}

int display(cir_queue *q)
{
    if (q->r == -1 && q->f == -1)
    {
        cout << "queue is empty" << endl;
    }
    else if (q->r >= q->f)
    {
        int i = q->f;
        while (i <= q->r)
        {
            cout << q->arr[i] << " ";
            i++;
        }
        cout << endl;
    }
    else
    {
        for (int i = q->f; i < q->size; i++)
        {
            cout << q->arr[i] << " ";
        }

        for (int i = 0; i <= q->r; i++)
        {
            cout << q->arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

int main()
{
    class cir_queue *q = new cir_queue();
    q->f = -1;
    q->r = -1;

    cout << "enter size of cicular queue" << endl;
    cin >> q->size;

    q->arr = new int();

    int choice = 1, x; // variables declaration

    while (choice < 4 && choice != 0) // while loop
    {
        printf("\n Press 1: Insert an element");
        printf("\nPress 2: Delete an element");
        printf("\nPress 3: Display the element");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("Enter the element which is to be inserted  ");
            scanf("%d", &x);
            enqueue(q, x);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            display(q);
            break;
        default:
            cout << "enter correct choise" << endl;
        }
    }
}