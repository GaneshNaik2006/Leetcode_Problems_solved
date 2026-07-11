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
    int search(vector<int>& inorder,int val,int left,int right){
        for(int i=left;i<=right;i++){
            if(inorder[i]==val) return i;
        }
        return -1;
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int& postidx,int left,int right){
        if(left>right) return NULL;

        TreeNode* root=new TreeNode(postorder[postidx]);
        // if(left==right) return root;
        int inidx=search(inorder,postorder[postidx],left,right);
        postidx--;
        root->right=helper(inorder,postorder,postidx,inidx+1,right);
        root->left=helper(inorder,postorder,postidx,left,inidx-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int postidx=n-1;
      return  helper(inorder,postorder,postidx,0,inorder.size()-1);

    }
};