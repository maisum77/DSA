#include <iostream>
#include <vector>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
static int idx = -1;
node *BuildTree(vector<int> preorder)
{
    idx++;
    if (preorder[idx] == -1)
    {
        return NULL;
    }
    node *root = new node(preorder[idx]);
    root->left = BuildTree(preorder);
    root->right = BuildTree(preorder);
    return root;
}
void pre_order(node* root)
{
    if (root==NULL)
    {
        return;
    }
    cout<<root->data<<endl;
    pre_order(root->left);
    pre_order(root->right);
}
void inorder(node* root)
{
    if (root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
void postorder(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;

}

int height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftht=height(root->left);
    int rightht=height(root->right);
    return max(leftht,rightht)+1;
}
int count(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftcount=count(root->left);
    int rightcount=count(root->right);
    return leftcount+rightcount+1;
}
int sum_node(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=sum_node(root->left);
    int right=sum_node(root->right);
    return left+right+root->data;
}
int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    node* root=BuildTree(preorder);
    // pre_order(root);
    // inorder(root);
    // postorder(root);
    // cout<<height(root);
    // cout<<count(root);
    cout<<sum_node(root);
    return 0;
}