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
bool search(node *root,int val)
{
    if(!root)
        return false;
    if(root->data==val)
        return true;
    if(root->data<val)
        return search(root->right,val);
    if(root->data>val)
        return search(root->left,val);
    return false;
}

void preorder(node *root)
{
    if(!root)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}


/****Function to traverse BST Iteratively *********/
void preorderIterative(node *root)
{
    stack<node *>st;
    while(true)
    {
        if(root)
        {
            st.push(root);
            cout<<root->data<<" ";
            root=root->left;
        }
        else
        {
            if(st.empty())
                return;
            root=st.top();
            st.pop();
            root=root->right;
        }
    }
    return;
}
int main()
{
    node *root = buildBST();
    cout<<endl;
    preorder(root);
    cout<<endl;
    preorderIterative(root);
    cout<<endl;
}