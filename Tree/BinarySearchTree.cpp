#include <iostream>
using namespace std;
int *tree = new int();
// line no 125 to 128 is main check that
int root(int a)
{
    if (tree[0] == 0)
    {

        tree[0] = a;
    }
    else
    {
        cout << "already have root " << endl;
    }
    return 0;
}

void setchild(int value, int index)
{
    if (tree[index] != 0) // line no 125 to 128
    {
        if (tree[index] > value)
        {
            setchild(value, 2 * index + 1); // check in left
        }
        else if (tree[index] < value)
        {
            setchild(value, 2 * index + 2); // check in right
        }
    }

    else
    {
        tree[index] = value;
    }
}

int print(int n)
{
    for (int i = 0; i < 100; i++)
    {
        if (tree[i] != 0) // line no 125 to 128
        {
            cout << tree[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
int preorder(int index) // root left right
{
    if (index >= 0 && tree[index] != 0) // line no 125 to 128
    {
        cout << tree[index] << " "; // root
        preorder(2 * index + 1);    // left child
        preorder(2 * index + 2);    // right child
        /*its create a stack to call recursively function
        again and again*/
    }
    return 0;
}
int postorder(int index) // left right root
{
    if (index >= 0 && tree[index] != 0) // line no 125 to 128
    {
        postorder(2 * index + 1);   // left child
        postorder(2 * index + 2);   // right child
        cout << tree[index] << " "; // root
    }
    return 0;
}
int inorder(int index) // left root right
{
    if (index >= 0 && tree[index] != 0) // line no 125 to 128
    {
        inorder(2 * index + 1);     // left child
        cout << tree[index] << " "; // root
        inorder(2 * index + 2);     // right child
    }
    return 0;
}
int search(int key, int index)
{ // recursive call function again and again
    if (tree[index] != 0)
    {
        if (tree[index] == key)
        {
            return index;
            // return index of key
        }
        else if (tree[index] > key)
        {
            return search(key, 2 * index + 1);
            // search in left subtree
        }
        else if (tree[index] < key)
        {
            return search(key, 2 * index + 2);
            // search in right subtree
        }
    }
    return -1;
    // if not found then return -1
}

// not working properly
int delet(int value)
{
    int result = search(value ,0); 
    // search whether elemet is present in tree or not
    // if present then return index of element 
    if(result ==-1)
    {
        cout<<value<<" is not present"<<endl;
    }
    else
    {
      tree[result] =0;
      cout<<value<<" deleted from tree "<<endl;
    }
}
int main()
{
    int n;
    int choice;
    cout << "enter total no of node " << endl;
    cin >> n;

    int A[n];
    cout << "enter tree element " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    // initializing tree array element with 0
    // for further process
    for (int i = 0; i < 100; i++)
    {
        tree[i] = 0;
    }

    //root(A[0]); // set the root

    for (int i = 0; i < n; i++)
    {
        setchild(A[i], 0);
    }

    int p = 1;
    do
    {   
        cout<<"enter choice"<<endl;
        cout << "1 for traversal on tree" << endl;
        cout << "2 for search node in tree " << endl;
        cout << "3 for add new node in tree" << endl;
        cout << "4 for delete node from tree" << endl;
        cout << "5 for exit" << endl;
        
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "tree look like" << endl;
            print(n);
            cout << "preorder traversal" << endl;
            preorder(0);
            cout << endl;
            cout << "postorder traversal" << endl;
            postorder(0);
            cout << endl;
            cout << "inorder traversal" << endl;
            inorder(0);
            cout << endl;
            break;
        }

        case 2: // binary search algorithm
        {
            cout << "enter node (value) to search in binary tree " << endl;
            int key;
            cin >> key;
            int result = search(key, 0);
            if (result == -1)
            {
                cout << key << " not present in binary tree" << endl;
            }
            else
            {
                cout << key << " present at " << result << " position " << endl;
                cout << "and parent node position is " << (result + 1) / 2 - 1 << endl;
            }
            break;
        }
        case 3:
        {
            cout << "enter element to add in tree" << endl;
            int add;
            cin >> add;
            setchild(add, 0);
            break;
        }

        case 4:
        {   cout << "enter element to delete from tree" << endl;
            int del;
            cin >> del;
            delet(del);
            break;
        }
        case 5:
        {
            exit(0);
        }
        }
    } while (p != 0);
}