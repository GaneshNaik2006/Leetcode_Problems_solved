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
     int maxd(TreeNode*  root){
        if(!root) return 0;
        int leftcount=maxd(root->left);
        int rightcount=maxd(root->right);
        return max(leftcount,rightcount)+1;
    }
    int height(TreeNode* root) {
        return maxd(root);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

       if( abs(height(root->left)-height(root->right)) >1) return false ;
       bool isleft=isBalanced(root->left);
       bool isright=isBalanced(root->right);

       return isleft&&isright;

    }
};