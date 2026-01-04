#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node()
    {
        left = right = NULL;
    }
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

node *insert_node(int val, node *root)
{
    if (root == NULL)
    {
        node *n = new node(val);
        return n;
    }
    if (root->data > val)
    {
        root->left = insert_node(val, root->left);
    }
    else
    {
        root->right = insert_node(val, root->right);
    }

    return root;
}

void traversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << endl;
    traversal(root->left);
    traversal(root->right);
}

bool search(node *root, int val)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == val)
    {
        return true;
    }
    if (root->data < val)
    {
        return search(root->right, val);
    }
    if (root->data > val)
    {
        return search(root->left, val);
    }
    else
    {
        return false;
    }
}

node *inordersussor(node *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

node *del(node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data > val)
    {
        root->left = del(root->left, val);
    }
    else if (root->data < val)
    {
        root->right = del(root->right, val);
    }
    else
    {
        // else part will run if the root->data==val then the value id found it will del the val
        // where all the three condition we check to dele the node

        // if the node have no child and 1 child then we can use this
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            // for two childs
            node *successor = inordersussor(root);
            root->data = successor->data;
            root->right = del(root->right, successor->data);
        }
    }
    return root;
}

int main()
{
    node *n = NULL;
    int arr[6] = {3, 2, 1, 5, 4, 6};
    for (int i = 0; i < 6; i++)
    {
        n = insert_node(arr[i], n);
    }
    cout<<"before="<<endl;
    traversal(n);
    del(n, 6);
    cout<<"after="<<endl;
    traversal(n);
    // cout<<search(n,3);
    return 0;
}