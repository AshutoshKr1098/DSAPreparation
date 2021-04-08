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
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if(root==NULL)
            return 0;
        
        int lsum = rangeSumBST(root->left,low,high);
        int rsum = rangeSumBST(root->right,low,high);
        int sum = lsum+rsum;
        if(low<=root->val && root->val<=high)
            sum+=root->val;
        return sum;         

    }
};