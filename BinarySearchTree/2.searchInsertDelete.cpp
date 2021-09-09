#include<bits/stdc++.h>
using namespace std; 

// Node structure for binary tree
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

/**
 * Method: InsertInBST
 * Arguments: 
 *      1. Root Node of tree
 *      2. Key to be inserted
 * Approach:
 *      1. If root is NULL(whether at first or recursively) we create a node and insert it.
 *      2. We recurse just like a normal BST recursion to find the appropriate position of that key.
 *      3. If in the matter of recursion, we find that the key is already present, we return that node
 *      4. Else, we will recurse till it's appropriate position, then create a node and insert it.
 * 
 * Note: A node is inserted always at the leaf node
*/

node* insert(node* root, int Key)
{    
    // if(!search(root,Key)) // I was first searching, but this was not needed, as I then added the logic at line 71
    // {
        if(root==NULL)
        {
            root = new node();
            root->left = NULL;
            root->right = NULL;
            root->data = Key;
            return root;
        }
        if(root->data==Key)
            return root;
        if(root->data>Key)
            root->left = insert(root->left,Key);
        if(root->data<Key)
            root->right = insert(root->right,Key);
        return root;
    
}

/**
 * Method: Search in a BST
 * Arguments: 
 *      1. root of tree
 *      2. element to search
 * Approach:
 *      1. If we hit root==NULL, that means in whole tree(or that subtree) we didnt find the element.
 *      2. If we find for a node, we return true
 *      3. recurse left and right as typical BST traversal
*/

bool search(node *root,int key)
{
    if(root==NULL)
        return false;
    if(root->data==key)
        return true;
    if(root->data>key)
        return search(root->left, key);
    if(root->data<key)
        return search(root->right, key);
}

/**
 * Method: Delete Node in a BST
 * Arguments: 
 *      1. root of tree
 *      2. element to delete
 * Approach:
 *      1. If root is null, so return NULL, as nothing to delete
 *      2. If root value is smaller than the value to be deleted, that means the deletion will take
 *          place on right subtree. And due to this deletion some structure of right tree will change
 *          so just root->right = delete(root->right,val)
 *          This line means, root will append to it's right, whatever structure it's right subtree will
 *          return post deletion.
 *      3. Same goes for left subtree
 *      4. Finally, if root is the node we were looking for to delete, then there will exist 3 cases
 *          a. it will have a left child but not a right child, so in this case just return the left child
 *          b. it will have a right child, so in this case return just the right child
 *          c. it will have both childs, so either go left, then go extreme end / or go right and turn 
 *             extreme left. 
 *          d. finally grabbing the correct node, replace it's value with root nodes vlu and delete this
 *             leaf node by calling this function again.
*/
node* deleteNode(node* root, int key) {
    if(root==NULL)
        return NULL;
    //Read it like this, if the value to be deleted is less than root's node, then it's left will contain
    //the new structure of left part, and root don't give a damn about it. It will just attach to it's left 
    //whatever is returned from it's left subtree after deletion.
    
    if(key<root->data)
        root->left= deleteNode(root->left,key);
    //Similarly for right subtree
    else if(key>root->data)
        root->right = deleteNode(root->right,key);
    else
    {
        if(!root->left && !root->right)
            return NULL;
        else if(root->left && !root->right)
            return root->left; //just return to it;s parent, it's left child, thus cutting the link btw parent and root
        else if(root->right && !root->left)
            return root->right;
        else
        {
            node* temp = root->right;
            while(temp->left)
                temp=temp->left;
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
            return root; //Now this root node holds the next greater value
        }
    }
    return root;
}
int main()
{    
    node *root= buildTree();    
}