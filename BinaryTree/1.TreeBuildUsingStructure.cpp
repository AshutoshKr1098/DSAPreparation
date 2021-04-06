#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left;
    node *right;
};

node *createNode(int x)
{
    node *temp = new node();
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node *buildTreePreorder(node *root)
{
    int d;
    cin >> d;
    if(d==-1)
        return NULL;

    root = createNode(d);
    root->left = buildTreePreorder(root->left);
    root->right = buildTreePreorder(root->right);
    return root;
}

/* Traversal of Binary Tree 
*   1. Preorder Traversal -> root left right
*   2. Inorder Traversal ->  left root right
*   3. Postorder Traversal -> left right root
*   4. Level Order Traversal
*/

void preorder(node *root)
{
    if(root==NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    return;
}
void inorder(node *root)
{
    if(root==NULL)
        return;    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    return;
}
void postorder(node *root)
{
    if(root==NULL)
        return;    
    postorder(root->left);    
    postorder(root->right);
    cout << root->data << " ";
    return;
}
bool helperPathtoNode(node *root,int n,vector<int>&v)
{    
    //Case-1 when we hit a NULL node 
    if(root==NULL)
        return false;    
    //Case-2 When we hit a leaf node which is not equal to n
    if(root->left==NULL && root->right==NULL && root->data!=n)
        return false;
    //Case-3 when we hit a leaf node which is equal to n
    if(root->left==NULL && root->right==NULL && root->data==n)
    {
        v.push_back(root->data);
        return true;
    }
    //Case-4 I often miss this case, this case is for intermediate nodes, which is equal to n
    if(root->data==n)
    {
        v.push_back(root->data);
        return true;
    }
    //Here we push again for intermediate node, but these might be popped later depending on left and right subtree's return value
    v.push_back(root->data);
    bool l = helperPathtoNode(root->left, n, v);
    bool r = helperPathtoNode(root->right, n, v);
    if(!l && !r)
    {
        v.pop_back();
        return false;
    }
    return true;
}
void pathToNode(node *root,int n)
{
    vector<int>v;
    bool res = helperPathtoNode(root,n,v);
    if(res)
    {
        for(auto it:v)
            cout<<it<<"->";
    }
    else
        cout<<v.size()<<endl;

}
int main()
{
    node *root = buildTreePreorder(root);
    pathToNode(root, 5);
}