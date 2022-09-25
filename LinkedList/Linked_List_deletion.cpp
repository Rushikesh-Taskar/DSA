#include <iostream>
using namespace std;
class del
{
public:
    int data;
    class del *next;
};
void print(class del *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << " " << endl;
}
//delete at begineening
class del *deleteatbegin(class del *head)
{
    class del *ptr ;
    ptr = head;
    head = ptr->next;
    free(ptr);
    return head;
}
//delete at index
class del *deleteatindex(class del *head, int index)
{
    class del *p;
    class del *q;
    p = head;
    q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

class del *deleteatend(class del *head)
{
    class del *p;
    class del *q;
    p = head;
    q = head->next;
    while(q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

int main()
{
    class del *head = new del();
    class del *second = new del();
    class del *third = new del();
    class del *fourth = new del();

   
    head->data = 4;
    head->next = second;

    second->data = 7;
    second->next = third;

    third->data = 8;
    third->next = fourth;

    fourth->data = 12;
    fourth->next = NULL;
    
    cout << "linked list before deletion :" << endl;
    print(head);
    cout << "linked list after deletion: " << endl;
    head=deleteatbegin(head);
    //head = deleteatindex(head, 2);
    //head= deleteatend(head);
    print(head);
}
