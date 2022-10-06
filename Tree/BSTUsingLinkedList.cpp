#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*  43 10 79 90 12 54 11 9 50   data for checking
        100
        /   \  
       /     \
      20      500
    /   \      / \                                                                                   \
    10   30   NULL NULL
   /  \  /   \
   /   \ null  NULL                                                                        \
  NULL NULL
*/

class node
{
public:
    int data;
    node *left;  // left node
    node *right; // right node
    node(int value)
    {
        data = value;
        left = NULL;  // left node null for further use
        right = NULL; // right node null for further use
    }
};

node *root = NULL; // root node

node *insert(node *root, int value)
{
    if (root == NULL)
    {
        node *newnode = new node(value);
        return newnode;
    }
    node *current =root;
    
      while(true)
      {
        if (current->data > value) // left sub tree if small
        {
            if(current->left!=NULL)
            {
                current=current->left;
            }
            else
            {
              current->left = new node(value);
              break;
            }
            //root->left = insert(root->left, value);
        }
        else // right subtree greater or equal
        {
            if(current->right!=NULL)
            {
                current=current->right;
            }
            else
            {
              current->right = new node(value);
              break;
            }
            //root->right = insert(root->right, value);
        }
      }
    return root;
}

node *preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    return 0;
}

node *inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    return 0;
}

node *postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    return 0;
}

void levelordertraversal(node *root) // o(n) time complexity
{
    int depth = 0;
    queue<node *> p;
    p.push(root);
    int width = 0; // max width of tree
    vector<vector<int>> ans;

    while (!p.empty())
    {
        int size = p.size();
        vector<int> temp;

        // max no of node in  level
        width = max(width, size);

        for (int i = 0; i < size; i++)
        {
            node *level = p.front();
            if (level->left != NULL)
            {
                p.push(level->left);
            }
            if (level->right != NULL)
            {
                p.push(level->right);
            }

            temp.push_back(level->data);
            p.pop();
        }
        depth++;
        ans.push_back(temp);
    }

    for (auto it : ans)
    {
        for (auto qt : it)
        {
            cout << qt << " ";
        }
    }
    cout << endl;

    cout << "depth of tree is " << depth << " by levelorder traversal" << endl;
}

void zigzagtraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> p;
    p.push(root);

    vector<vector<int>> ans;

    bool flag = true; // tell us to store in reverse or same order in ans

    while (!p.empty())
    {
        int size = p.size();
        vector<int> temp;
        for (int i = 0; i < size; i++)
        {
            node *level = p.front();
            if (level->left != NULL)
            {
                p.push(level->left);
            }
            if (level->right != NULL)
            {
                p.push(level->right);
            }

            temp.push_back(level->data);
            p.pop();
        }
        if (flag)
        {
            ans.push_back(temp);
            flag = false;
        }
        else
        {
            reverse(temp.begin(), temp.end()); // right to left
            ans.push_back(temp);
            flag = true;
        }
    }

    for (auto it : ans)
    {
        for (auto qt : it)
        {
            cout << qt << " ";
        }
    }
    cout << endl;
}

bool isleaf(node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    return false;
}

void addleftboundary(node *root, vector<int> &res)
{
    node *temp = root->left;

    while (temp)
    {
        if (!isleaf(temp)) // if not leaf then add it
        {
            res.push_back(temp->data);
        }
        if (temp->left != NULL)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
}

void addrightboundary(node *root, vector<int> &res)
{
    node *temp = root->right;
    vector<int> cur;
    while (temp)
    {
        if (!isleaf(temp)) // if not leaf then add it
        {
            cur.push_back(temp->data);
        }
        if (temp->right != NULL)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    for (int i = cur.size() - 1; i >= 0; i--) // reverse order
    {
        res.push_back(cur[i]);
    }
}

void addleaves(node *root, vector<int> &res) // by preorder traversal
{
    if (isleaf(root)) // if  leaf then add it
    {
        res.push_back(root->data); // root
        return;
    }
    if (root->left)
    {
        addleaves(root->left, res); // left
    }
    if (root->right)
    {
        addleaves(root->right, res); // right
    }
}

void boundarytraversal(node *root) // anticlock wise
{
    vector<int> res;
    if (root == NULL)
    {
        return;
    }
    if (!isleaf(root)) // if not leaf then add it
    {
        res.push_back(root->data);
    }

    addleftboundary(root, res);
    addleaves(root, res); // from left to right by preorder traversal
    addrightboundary(root, res);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

void iterativepreorder(node *root)
{
    stack<node *> s;
    vector<int> preorder;
    s.push(root);
    if (root == NULL)
    {
        return;
    }
    while (!s.empty())
    {
        root = s.top();
        s.pop();
        preorder.push_back(root->data);

        if (root->right != NULL)
        {
            s.push(root->right);
        }
        if (root->left != NULL)
        {
            s.push(root->left);
        }
    }
    for (auto it : preorder)
    {
        cout << it << " ";
    }
    cout << endl;
}

void iterativeinorder(node *root)
{
    stack<node *> s;
    vector<int> inorder;
    bool p = true;
    while (p == true)
    {

        if (root != NULL)
        {
            s.push(root);
            root = root->left;
        }

        else
        {
            if (s.empty() == true)
            {
                break;
                p = false;
            }
            root = s.top();
            s.pop();
            inorder.push_back(root->data);
            root = root->right;
        }
    }
    for (auto it : inorder)
    {
        cout << it << " ";
    }
    cout << endl;
}

void iterativepostorder(node *root)
{
    stack<node *> st1;
    stack<node *> st2;

    if (root == NULL)
    {
        return;
    }
    st1.push(root);
    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        if (root->left != NULL)
        {
            st1.push(root->left);
        }
        if (root->right != NULL)
        {
            st1.push(root->right);
        }
        st2.push(root);
    }

    node *temp;
    while (!st2.empty())
    {
        temp = st2.top();
        st2.pop();
        cout << temp->data << " ";
    }
    cout << endl;
}

// without stack and without recursion
void morrisinorder(node *root)
{
    vector<int> inorder;
    node *current = root;
    while (current != NULL)
    {
        // if left is  null means store we are at root node  , no left exist
        if (current->left == NULL)
        {
            inorder.push_back(current->data);
            current = current->right; // move to right
        }

        else
        {
            node *previous = current->left; // for connection
                                            // previous->right == current means connection is present
            while (previous->right && previous->right != current)
            {
                previous = previous->right; // for connection
            }

            // made the connection  and move to left
            if (previous->right == NULL)
            {
                previous->right = current;
                current = current->left;
            }

            // remove the connection and move to right store the data
            else
            {
                previous->right = NULL;
                inorder.push_back(current->data);
                current = current->right;
            }
        }
    }
    for (auto it : inorder)
    {
        cout << it << " ";
    }
    cout << endl;
}

void morrispreorder(node *root)
{
    vector<int> preorder;
    node *current = root;
    while (current != NULL)
    {
        // if left is  null means store we are at root node  , no left exist
        if (current->left == NULL)
        {
            preorder.push_back(current->data); // store data
            current = current->right;          // move to right
        }

        else
        {
            node *previous = current->left; // for connection
                                            // previous->right == current means connection is present
            while (previous->right && previous->right != current)
            {
                previous = previous->right; // for connection
            }

            // made the connection  and move to left store the data
            if (previous->right == NULL)
            {
                previous->right = current;
                preorder.push_back(current->data);
                current = current->left;
            }

            // remove the connection and move to right
            else
            {
                previous->right = NULL;
                current = current->right;
            }
        }
    }
    for (auto it : preorder)
    {
        cout << it << " ";
    }
    cout << endl;
}

int depthoftree(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = depthoftree(root->left);
    int rh = depthoftree(root->right);

    return 1 + max(lh, rh); // left hand and right hand
}

int search(node *root, int value)
{
    if (root != NULL)
    {
        if (root->data == value)
        {
            cout << value << " is present in tree" << endl;
        }
        else if (root->data > value)
        {
            return search(root->left, value);
        }
        else
        {
            return search(root->right, value);
        }
    }
    else
    {
        cout << value << " is not present in tree" << endl;
    }
    return 0;
}

node *inpredecessor(node *root) // for delete operation
{                               // inorderpredecessor is the root's , left root's right most child
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

node *inordersuccessor(node *root)
{
    // inordersuccessor is the root's , right root's left most child
    root = root->right;

    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

node *deletehelper(node *root)
{

  if(root->left==NULL)
  {  
      // if left is NULL then replace by  right part 
    return root->right;
  }
  else if(root->right==NULL)
  {  // if right of value node is null then replace by left tree
    return root->left;
  }

   node *rightsubtree=root->right;
   node *inorderpredecessor=inpredecessor(root);

   inorderpredecessor->right=rightsubtree;  
   // right subtree connection in rightmost child's right to  maintain BST property
   
   return root->left;   // left child

}

node *deletenode(node *root, int value)
{   
    // if value found replace it by left node and connect right subtree to
    //  right of inorderpredecessor so that tree remain BST 
    
    node *mainroot = root;

    if (root == NULL)
    {
        return NULL;
    }
    if(root->data==value)  // if value is at root 
    {
        return deletehelper(root);  // replace by left child
    }
    while(root != NULL)
    {
        if (root->data > value)
        {   //root->left->data because we need previous root further for connection 
            // so chech root->right->data or root->left->data like this 
            if (root->left !=NULL && root->left->data==value )
            {
               root->left =deletehelper(root->left);  // connection part 
               break;
            }
            else
            {
                root = root->left;   // move to left
            }
        }
        else
        {
           if (root->right !=NULL && root->right->data==value )
            {
               root->right =deletehelper(root->right);   // do the connection 
               break;
            }
           else
           {
               root =root->right;   // move to right 
           }
        }
    }

    return mainroot;
}

int main()
{

    int n;
    int choice;
    cout << "enter total no of node " << endl;
    cin >> n;
    cout << "enter value of node " << endl;
    while (n--)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    
    //int val;
   // cin>>val;
   //root= deletenode(root ,val);
    cout << "inorder traversal on tree" << endl;
    inorder(root);
    cout << endl;
    iterativeinorder(root);
    morrisinorder(root);
    cout << "preorder traversal on tree" << endl;
    preorder(root);
    cout << endl;
    iterativepreorder(root);
    morrispreorder(root);
    cout << "postorder traversal on tree" << endl;
    postorder(root);
    cout << endl;
    iterativepostorder(root);
    cout << "level order traversal (BFS)" << endl;
    levelordertraversal(root);
    cout << "zigzag  order traversal" << endl;
    zigzagtraversal(root);
    cout << "boundary order traversal anticlockwise" << endl;
    boundarytraversal(root);
    cout << "depth of binary tree " << depthoftree(root) << " by recursive call " << endl;
    int m;
    cout << "enter element to search in tree" << endl;
    cin >> m;
    search(root, m);
}
