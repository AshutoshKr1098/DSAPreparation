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
{
{
    cin >> d;
    if(d==-1)
        return NULL;

    root = createNode(d);
{
*   3. Postorder Traversal -> left right root
*   4. Level Order Traversal
*/

void preorder(node *root)
{
{)
{    
    //Case-1 when we hit a NULL node 
    if(root==NULL)
{
        return true;
    }
    //Case-4 I often miss this case, this case is for intermediate nodes, which is equal to n
    if(root->data==n)
    {
        v.push_back(root->data);
        return true;
    }
{
    vector<int>v;
    bool res = helperPathtoNode(root,n,v);
{
    if(res)
    {
        for(auto it:v)
            cout<<it<<"->";
    }
    else
        cout<<v.size()<<endl;

}
node *insertIntoBT(node *root,int n)
{
    if(!root)
    {
        root = createNode(n);
        return root;
    }
    if(!root->left)
    {
        root->left = createNode(n);
        return root->left;
    }
    if(!root->right)
    {
        root->right = createNode(n);
        return root->right;
    }
}
int main()
{
    node *root = NULL;
    root = buildTreePreorder(root);
    int num;
    cin >> num;
    insertIntoBT(root, num);
    pathToNode(root, 5);
}