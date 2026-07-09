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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        
        q.push(root);
        ans.push_back(root->val);
        q.push(NULL);
        bool x=true;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();

            if(curr==NULL){
                if(!q.empty()){
                    x=true;
                    q.push(NULL);
                    continue;
                }else break;
            }
            if(curr->right){
                if(x) ans.push_back(curr->right->val);
                x=false;
                q.push(curr->right);
            }
            if(curr->left){
                if(x) ans.push_back(curr->left->val);
                x=false;
                q.push(curr->left);
            }
        }
        return ans;

    }
};