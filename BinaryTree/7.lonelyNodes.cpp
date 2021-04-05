/**
 * Problem: Leetcode easy
 * Approach: level order traversal. Insert into vector only those nodes whose only 1 child exist. 
 * Then push all childs into queue. Repeat this while queue is not empty
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int>lonely;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if(temp->left && !temp->right)
                lonely.push_back(temp->left->val);
            else if(temp->right && !temp->left)
                lonely.push_back(temp->right->val);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);            
        }
        return lonely;
    }
};