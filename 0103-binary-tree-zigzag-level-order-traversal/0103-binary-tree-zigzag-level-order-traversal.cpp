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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<vector<int>> ans;
        vector<int> temp;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();

            if(curr){
                temp.push_back(curr->val);
            }else{
                if(q.empty()) break;
                else{
                    ans.push_back(temp);
                    temp={};
                    q.push(NULL);
                    continue;
                }
            }

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        if(!temp.empty()) ans.push_back(temp);
        int n=ans.size();

        for(int i=0;i<n;i++){
            if(i&1) reverse(ans[i].begin(),ans[i].end());
        }

        return ans;
    }
};