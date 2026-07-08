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
    int count=0;
    int maxd(TreeNode*  root){
        if(!root) return 0;
        int leftcount=maxd(root->left);
        int rightcount=maxd(root->right);
        return max(leftcount,rightcount)+1;
    }
    int maxDepth(TreeNode* root) {
        return maxd(root);
    }
};