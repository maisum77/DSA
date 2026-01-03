#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    // constructor
    TreeNode(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int countNodes(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int countLeaves(TreeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return countLeaves(root->left) + countLeaves(root->right);
    }
}

int countFullNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int isFull;
    if (root->left && root->right)
    {
        isFull = 1;
    }
    else
    {
        isFull = 0;
    }

    return isFull + countFullNodes(root->left) + countFullNodes(root->right);
}

bool isBSTUtil(TreeNode *root, int minVal, int maxVal)
{
    if (root == NULL)
        return true;
    if (root->data <= minVal || root->data >= maxVal)
        return false;
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(TreeNode *root)
{
    return isBSTUtil(root, -1000000, 1000000); // garbish value 
}

bool isComplete(TreeNode *root)
{
    if (root == nullptr)
        return true;

    queue<TreeNode *> q;
    q.push(root);
    bool foundNull = false;

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (node == nullptr)
        {
            foundNull = true;
        }
        else
        {
            if (foundNull)
                return false;
            q.push(node->left);
            q.push(node->right);
        }
    }
    return true;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);

    cout << "Nodes: " << countNodes(root) << endl;
    cout << "Leaves: " << countLeaves(root) << endl;
    cout << "Full Nodes: " << countFullNodes(root) << endl;
    cout << "Is BST: " << (isBST(root) ? "Yes" : "No") << endl;
    cout << "Is Complete: " << (isComplete(root) ? "Yes" : "No") << endl;

    return 0;
}