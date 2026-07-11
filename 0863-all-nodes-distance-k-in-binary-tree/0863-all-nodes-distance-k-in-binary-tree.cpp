/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent){
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();

            if(curr->left){
                q.push(curr->left);
                parent[curr->left]=curr;
            }
            if(curr->right){
                q.push(curr->right);
                parent[curr->right]=curr;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        unordered_map<TreeNode*,TreeNode*> parent;

        markparent(root,parent);
        unordered_map<TreeNode*,bool> visted;
        queue<TreeNode*> q;
        q.push(target);
        visted[target]=true;
        int currsize=0;
        while(!q.empty()){
            
            if(currsize==k) break;
            currsize++;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !visted[curr->left]){
                    q.push(curr->left);
                    visted[curr->left]=true;
                }
                if(curr->right && !visted[curr->right]){
                    q.push(curr->right);
                    visted[curr->right]=true;
                }
                if(parent[curr] && !visted[parent[curr]]){
                    q.push(parent[curr]);
                    visted[parent[curr]]=true;
                }
            }
        }

        vector<int> result;

        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};