#include "iostream"
using namespace std;
class node
{
public:
    int data;
    class node *next;
};
//linked list traversal
void linkedlisttraversal(class node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
//insertion at begineening
//time complexity O(1) const
class node *insertatbegin(class node *head, int data)
{
    class node *ptr = (class node *)malloc(sizeof(class node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
//insertion at index
//time complexity O(n)
class node *insertatindex(class node *head, int data, int index)
{
    class node *ptr = (class node *)malloc(sizeof(class node));
    class node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
//insert at endl
//time complexity O(n)
class node *insertatend(class node *head, int data)
{
    class node *ptr = (class node *)malloc(sizeof(class node));
    class node *p = head;
    int i = 0;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;
    return head;
}
//insert at node
//time complexity O(1) const
class node *insertafternode(class node *head, class node *previouse, int data)
{
    class node *ptr = new node();
    ptr->data = data;
    ptr->next = previouse->next;
    previouse->next = ptr;
    return head;
}

int main()
{
    class node *head = new node();
    class node *second = new node();
    class node *third = new node();

    //head = (class node *)malloc(sizeof(class node));
    //second = (class node *)malloc(sizeof(class node));
    //third = (class node *)malloc(sizeof(class node));

    head->data = 7;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 11;
    third->next = NULL;
    cout << "linked list before insertion" << endl;
    linkedlisttraversal(head);
    cout << " " << endl;
    cout << "linked list after insertion" << endl;

    //function calling

    //head = insertatbegin(head, 5);
    // head = insertatindex(head, 3, 1);
    //head = insertatend(head, 12);
    head = insertafternode(head, second, 4);
    linkedlisttraversal(head);
}