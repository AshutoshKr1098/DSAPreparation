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
    node *temp= new node();
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/*** Construct a BST from given preorder traversal of tree*****/
node *constructBSTFromPreorder(vector<int> v)
{
    stack<node *> st;
    node *root = createNode(v[0]);
    st.push(root);
    for (int i = 1; i < v.size(); i++)
    {
        node *par = st.top();
        node *curr = createNode(v[i]);
        while(!st.empty() && st.top()->data<v[i])
        {
            par=st.top();
            st.pop();
        }
        if(v[i]<par->data)
        {
            par->left = curr;
            st.push(curr);
        }
        else
        {
            par->right = curr;
            st.push(curr);
        }
    }
    return root;
}
int main()
{
    vector<int> v;
    int d;
    cin >> d;
    v.push_back(d);
    while (d!=-1)
    {
        cin >> d;
        v.push_back(d);
    }
    node *root = constructBSTFromPreorder(v);
}