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
int main()
{
    node *root = buildTreePreorder(root);
}