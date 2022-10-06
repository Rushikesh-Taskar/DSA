#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

node *treefrominandposthelper(vector<int> &inorder, int instart, int inend, vector<int> &postorder, int poststart, int postend, map<int, int> &inindex)
{
    if (poststart > postend || instart > inend)
    {
        return NULL;
    }

    node *root = new node(postorder[postend]); // root node is postorder last value

    // position of postorder's last node in inorder traversal
    int rootindex = inindex[postorder[postend]];

    int totalleftnode = (rootindex - instart); // no of left side node

    // left subtree
    root->left = treefrominandposthelper(inorder, instart, rootindex - 1, postorder, poststart, poststart + totalleftnode - 1, inindex);

    // right subtree
    root->right = treefrominandposthelper(inorder, rootindex + 1, inend, postorder, poststart + totalleftnode, postend - 1, inindex);

    return root; // main root
}

node *treefrominandpost(vector<int> &inorder, vector<int> &postorder)
{
    if (inorder.size() != postorder.size()) // if size is not equal then null
    {
        return NULL;
    }
    map<int, int> inindex;
    // to store position in inorder traversal to
    // calculate left and right node count

    for (int i = 0; i < inorder.size(); i++)
    {
        inindex[inorder[i]] = i;
    }

    return treefrominandposthelper(inorder, 0, (inorder.size() - 1), postorder, 0, (postorder.size() - 1), inindex);
}

node *treefrominandprehelper(vector<int> &inorder, int instart, int inend, vector<int> &preorder, int prestart, int preend, map<int, int> &inindex)
{
    if (prestart > preend || instart > inend)
    {
        return NULL;
    }

    node *root = new node(preorder[prestart]); // root node is postorder last value

    // position of postorder's last node in inorder traversal
    int rootindex = inindex[preorder[prestart]];

    int totalleftnode = (rootindex - instart); // no of left side node

    // left subtree
    root->left = treefrominandprehelper(inorder, instart, rootindex - 1, preorder, prestart+1, prestart + totalleftnode, inindex);

    // right subtree
    root->right = treefrominandprehelper(inorder, rootindex + 1, inend, preorder, prestart + totalleftnode+1, preend, inindex);

    return root; // main root
}

node *treefrominandpre(vector<int> &inorder, vector<int> &preorder)
{
    if (inorder.size() != preorder.size()) // if size is not equal then null
    {
        return NULL;
    }
    map<int, int> inindex;
    // to store position in inorder traversal to
    // calculate left and right node count

    for (int i = 0; i < inorder.size(); i++)
    {
        inindex[inorder[i]] = i;
    }

    return treefrominandprehelper(inorder, 0, (inorder.size() - 1), preorder, 0, (preorder.size() - 1), inindex);
}



// function for testing
void preordertraversal(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preordertraversal(root->left);
        preordertraversal(root->right);
    }
    return;
}

void inordertraversal(node *root)
{
    if (root != NULL)
    {
        inordertraversal(root->left);
        cout << root->data << " ";
        inordertraversal(root->right);
    }
    return;
}

void postordertraversal(node *root)
{
    if (root != NULL)
    {
        postordertraversal(root->left);
        postordertraversal(root->right);
        cout << root->data << " ";
    }
    return;
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

// node *rootnode =NULL ;

int main()
{

    int n;
    cout << "enter total no of node" << endl;
    cin >> n;

    vector<int> inorder;
    vector<int> postorder;
    vector<int> preorder;
    cout << "please enter inorder traversal" << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        inorder.push_back(x);
    }

    cout << "please enter postorder traversal" << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        postorder.push_back(x);
    }
    
     cout << "please enter preorder traversal" << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        preorder.push_back(x);
    }
    
    //node *rootnode = treefrominandpost(inorder, postorder);
    node *rootnode = treefrominandpre(inorder, preorder);
   
   
    inordertraversal(rootnode);
    cout<<endl;
    postordertraversal(rootnode);
    cout<<endl;
    preordertraversal(rootnode);
    cout<<endl;
    zigzagtraversal(rootnode);
    return 0;
}