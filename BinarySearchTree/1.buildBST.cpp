/****************** Binary Search Tree ***********************/

#include<bits/stdc++.h>
using namespace std;

//Step-1 Create a struct node
struct node
{
    int data;
    node *left;
    node *right;
};

//Step-2 Create a method that returns a new node
node *createNode(int x)
{
    node *temp=new node();
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

//Step-3 Create a method that take root and value as parameter and insert value at appropriate leaf node
node *insertIntoBST(node *root,int val)
{
    if(!root)
    {
        root=createNode(val);
        return root;
    }
    //No funda for equal to, strictly unique keys to be present in BST
    if(root->data>val)
        root->left=insertIntoBST(root->left,val);
    if(root->data<val)
        root->right = insertIntoBST(root->right,val);
    return root;
}

//Step-4 Create a wrapper method, that reads the input from console and builds a BST until -1 is found
node *buildBST()
{
    node *root=NULL;
    int d;
    cin>>d;
    while(d!=-1)
    {
        root=insertIntoBST(root,d);
        cin>>d;
    }
    return root;
}

//Step-5 Finally Print the BST in inorder traversal to give a sorted output of integer
void inorder(node *root)
{
    if(root==nullptr)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
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

int main()
{
    node *root = buildBST();
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
}
