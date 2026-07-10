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
    void nodes(TreeNode* root){
        if(!root) return ;

        count++;
        nodes(root->left);
        nodes(root->right);
    }
    int countNodes(TreeNode* root) {
        nodes(root);
        return count;
    }
};