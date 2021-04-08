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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //to always ensure, p denotes lesser element, q denotes greater element
        // this is done for my clarity just.
        if(p->val > q->val)
        {
            TreeNode *temp = p;
            p=q;
            q=temp;
        }        
        if(!root)
            return NULL;
        //since all nodes are unique and keys are sure to be present
        if(root->val==p->val || root->val ==q->val)
            return root;
        
        //if smaller one (p) is in left side and greater one is in right
        if(p->val < root->val && root->val<q->val)
            return root;
        //if both are in left
        if(p->val<root->val && q->val<root->val)
            return lowestCommonAncestor(root->left,p,q);
        //if both are in right
        if(p->val>root->val && q->val>root->val)
            return lowestCommonAncestor(root->right,p,q);
        return NULL;       
        
    }
};