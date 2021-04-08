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

//Solution-1 using Inorder traversal : Tc=O(N) Sc = O(n)
class Solution
{
public:
    void inorder(TreeNode *root,vector<int>&v)
    {
        if(root==NULL)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
        return;
    }
    bool isValidBST(TreeNode* root) {        
        vector<int>v;
        inorder(root,v);
        for(int i=0;i<v.size()-1;i++)
            if(v[i]>=v[i+1])
                return false;
        return true;           
        
    }
};

class Solution2 {
public:  
    bool valid(TreeNode *root,long mx, long mn) //int mn and mx gave error[typical leetcode lol]
    {
        if(root==NULL)
            return true;           
        if(mn<root->val && root->val<mx)
        {
            return (valid(root->left,root->val,mn) && valid(root->right,mx,root->val));
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return valid(root,LONG_MAX,LONG_MIN);
        
    }
};