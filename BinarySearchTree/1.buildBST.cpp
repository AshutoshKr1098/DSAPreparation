#include<bits/stdc++.h>
using namespace std; 

struct node
{
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
node *insertInBST(node *root,int d)
{
    if(root==NULL)
    {
        root= createNode(d);
        return root;
    }
    if(d<=root->data)
        root->left=insertInBST(root->left,d);
    if(d>root->data)
        root->right = insertInBST(root->right,d);
    return root;
}
node* buildTree()
{
    int d;
    cin>>d;
    node *root=NULL;
    while(d!=-1)
    {        
        root=insertInBST(root,d);
        cin>>d;
    }
    return root;
}
void inOrder(node *root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
    return;
}
void levelOrder(node *root)
{
    queue<node *>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        
    }
    return;
}
void preorder(node* root)
{
    if(root==NULL)
        return;
    cout<<root->data << " ";
    preorder(root->left);
    preorder(root->right);
    return;
}
int main()
{    
    node *root= buildTree();
    preorder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    levelOrder(root);
}