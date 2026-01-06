#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    int height;
    node(int val)
    {
        data = val;
        left = right = NULL;
        height = 1;
    }
};
int getheight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}
int getbalance(node *root)
{
    return getheight(root->left) - getheight(root->right);
}
node *rightRotation(node *root)
{
    node *child = root->left;
    node *childright = child->right;

    child->right = root;
    // ERROR WAS HERE: child->left = childright;
    root->left = childright; // CORRECT: root adopts the orphan subtree

    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));
    return child;
}

node *leftRotation(node *root)
{
    node *child = root->right;
    node *childleft = child->left;

    child->left = root;
    // ERROR WAS HERE: child->right = childleft;
    root->right = childleft; // CORRECT: root adopts the orphan subtree

    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));
    return child;
}

node *insert(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    else if (root->data > val)
    {
        root->left = insert(root->left, val);
    }
    else if (root->data < val)
    {
        root->right = insert(root->right, val);
    }
    else
    {
        return root;
    }

    // for height
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    // for getting the balance after adding the node
    int balance = getbalance(root);

    // LL
    if (balance > 1 && root->left != NULL && root->left->data > val)
    {
        return rightRotation(root);
    }
    // LR
    else if (balance > 1 && root->left != NULL && root->left->data < val)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    // RR
    else if (balance < -1 && root->right != NULL && root->right->data < val)
    {
        return leftRotation(root);
    }
    // RL
    else if (balance < -1 && root->right != NULL && root->right->data > val)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    // no unbalancing
    else
    {
        return root;
    }
};
void pre_order(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << endl;
    pre_order(root->left);
    pre_order(root->right);
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << endl;
}
int main()
{
    node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 90);
    root = insert(root, 50);
    root = insert(root, 1);
    root = insert(root, 22);
    root = insert(root, 45);
    root = insert(root, 65);
    pre_order(root);
    cout<<endl;
    inorder(root);
}
