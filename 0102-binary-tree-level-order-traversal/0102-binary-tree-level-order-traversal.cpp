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
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);
        q.push(NULL);
        if(root==NULL) return {};
        ans.push_back({root->val});
        vector<int> temp;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            
            if(curr==NULL){
                if(!q.empty()){
                    q.push(NULL);
                    ans.push_back(temp);
                    temp={};
                    continue;
                }else break;
            }

             if(curr->left){
                temp.push_back(curr->left->val);
                q.push(curr->left);
            }
            if(curr->right){
                temp.push_back(curr->right->val);
                q.push(curr->right);
            }
            
           
        }
        return ans;
    }
};