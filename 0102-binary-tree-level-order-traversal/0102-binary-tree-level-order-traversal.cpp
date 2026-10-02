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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root) return {};
        
        q.push(root);
        q.push(NULL);

        vector<vector<int>> ans;
        vector<int> temp;
        while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();

        if(!curr){
           if(!q.empty()){
                ans.push_back(temp);
                temp={};
                q.push(NULL);
                continue;
           } else break;
        }

        temp.push_back(curr->val);
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);

        }
        if(temp.size()>0) ans.push_back(temp);
       return ans;
    }
};