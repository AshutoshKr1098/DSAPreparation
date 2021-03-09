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

/**
 *  Iterative ways to traverse a tree. Here we will go through iterative methods of preorder postorder inorder
 * and level order traversal of a tree.
*/

//1. Preorder Traversal [ Use Stack, just mimic the recursive call stack]

/**
 * In this we have two different iterative approaches, one is very straight forward, other needs to be
 * memorized.
*/

//Method-1 . Preorder Traversal

vector<int> preorder1(node *root) {
    vector<int> res;
    if (root == NULL)
        return;
    stack<node *> st;
    st.push(root);
    while(!st.empty())
    {
        node *temp = st.top();
        st.pop();
        res.push_back(temp->data);
        //This order is important, first push right then left. Else it will give wrong output
        if(temp->right)
            st.push(temp->right);
        if(temp->left)
            st.push(temp->left);
    }
    return res;
}
//Method2 Preorder- a more intuitive visualised way(need to brush up few times)
vector<int>preorder2(node *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    stack<node *> st;
    while(true)
    {
        if(root!=NULL)
        {
            st.push(root);
            res.push_back(root->data);
            root = root->left;
        }
        else
        {
            if(st.empty())
                return res;
            root = st.top();
            st.pop();
            root = root->right;
        }
    }
}

int main()
{
    node *root = buildTreePreorder(root);
    vector<int>res= preorder1(root);
}