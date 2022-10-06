#include <iostream>
using namespace std;
class queue
{
public:
    int size;
    int f;       // frontend for dequeue
    int b;      // backend  for enqueue
    int *arr;    // int array
};
int isFull(class queue *q)
{
    if (q->b == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(class queue *q)
{
    if (q->b == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int enqueue(class queue *q, int val)    //insertion
{
    if (isFull(q))
    {
        cout << "queue overflow " << endl;
        return 0;
    }
    else
    {
        q->b++;
        q->arr[q->b] = val;
        cout << "enqueued element is:" << val << endl;
        return 0;
    }
}
int dequeue(class queue *q)      //deletion
{
    if (isEmpty(q))
    {
        cout << "queue  underflow " << endl;
    }

    else
    {
        q->f++;
        int del = q->arr[q->f];
        cout<<"dequeued element is "<<del<<endl;
    }
    return 0;
}
int print(queue *q)
{
   for(int i=q->f+1 ;i<=q->b;i++)
   {
       cout<<q->arr[i]<<" ";
   }cout<<endl;
   return 0;
}
int main()
{
    class queue *q = new queue();
    int n;
    cout<<"enter size of queue"<<endl;
    cin>>n;
    q->size = n;
    q->f = -1;       //front pointer
    q->b = -1;       // back pointer
    q->arr = new int();   //int array

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
               enqueue(q ,x);
                break;
            }
            case 2:
            {
               dequeue(q);
               break;
            }
            case 3:
            {   
                print(q);
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
    
    /*cout << "queue is empty ? " << isEmpty(q) << endl;
    cout << "queue is Full ? " << isFull(q) << endl;

    enqueue(q, 12);
    enqueue(q, 13);
    enqueue(q, 14);
    enqueue(q, 15);
    enqueue(q, 16);
    enqueue(q, 17);

    cout << "queue is empty ? " << isEmpty(q) << endl;
    cout << "queue is Full ? " << isFull(q) << endl;

    cout << "dequeued element is :" << dequeue(q) << endl;
    cout << "dequeued element is :" << dequeue(q) << endl;
    cout << "dequeued element is :" << dequeue(q) << endl;
    cout << "dequeued element is :" << dequeue(q) << endl;
    cout << "dequeued element is :" << dequeue(q) << endl;

    cout << "queue is empty ? " << isEmpty(q) << endl;
    cout << "queue is Full ? " << isFull(q) << endl;    //drawback of linear queue */
}