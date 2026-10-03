/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=-1e9;
    int maxPathSum1(TreeNode* root) {
        if(!root) return -1e9;
        if(!root->left && !root->right) {
            ans = max(ans, root->val); 
            return root->val;} 
        int left=max(0,maxPathSum1(root->left));
        int right=max(0,maxPathSum1(root->right));
        ans=max(ans,left+right+root->val);
       return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
       
       maxPathSum1(root);
       return ans;
    }
};