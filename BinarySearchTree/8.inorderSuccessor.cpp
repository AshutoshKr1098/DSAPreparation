#include<bits/stdc++.h>
using namespace std; 
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
        //if p right exists, then minimum element in the right will be the answer
        if(p->right!=NULL)
        {
            TreeNode* temp= p->right;
            while(temp->left!=NULL)
                temp=temp->left;
            return temp;
        }
        
        //Else we have to return the ancestor for which this node is a left child
        else
        {
            TreeNode* anc=root,*succ=NULL;
            while(anc!=p)
            {
                if(p->val < anc->val)
                {
                    succ=anc;
                    anc=anc->left;
                }
                else
                    anc=anc->right;
            }
            return succ;
        }
        
    }
};


//Solution using parent pointer

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        
        if(node->right)
        {
            Node* temp = node->right;
            while(temp->left)
                temp=temp->left;
            return temp;
        }
        else
        {
            Node* p = node->parent;
            while(p && p->right==node)
            {
                node= p;
                p=node->parent;
            }
            return p;
        }
        
    }
};