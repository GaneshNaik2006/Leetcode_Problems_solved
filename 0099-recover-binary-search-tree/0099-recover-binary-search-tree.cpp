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
    vector<int> ans;
    TreeNode* first=NULL;
    TreeNode* last=NULL;
    int i=0;
    void inorder(TreeNode* root){
        if(!root) return ;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }

    void inorder1(TreeNode* root){
          if(!root) return ;
        inorder1(root->left);
        if(!first && ans[i]!=root->val){
            first=root;
        }else if(!last&& ans[i]!=root->val){
            last=root;
        }
        i++;
        inorder1(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(ans.begin(),ans.end());
        inorder1(root);
        if(first && last )swap(first->val,last->val);
        
    }
};