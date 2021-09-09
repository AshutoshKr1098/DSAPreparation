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
    node *temp=new node();
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

node *insertIntoBST(node *root,int d)
{
    if(!root)
    {
        root=createNode(d);
        return root;
    }
    if(root->data>d)
        root->left = insertIntoBST(root->left,d);
    if(root->data<d)
        root->right = insertIntoBST(root->right,d);
    return root;
}
node *buildBST()
{
    int d;
    cin>>d;
    node *root=NULL;
    while(d!=-1)
    {
        root=insertIntoBST(root,d);
        cin>>d;                
    }
    return root;
}
void inorder(node *root)
{
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}
void inorderIterative(node *root)
{
    stack<node *>st;
    while(true)
    {
        if(root)
        {
            st.push(root);
            root=root->left;
        }
        else
        {
            if(st.empty())
                return;
            root=st.top();
            st.pop();            
            cout<<root->data<<" ";
            root=root->right;
        }
    }
    return;
}
int main()
{
    node *root = buildBST();
    inorder(root);
    cout<<endl;
    inorderIterative(root);
    cout<<endl;
}