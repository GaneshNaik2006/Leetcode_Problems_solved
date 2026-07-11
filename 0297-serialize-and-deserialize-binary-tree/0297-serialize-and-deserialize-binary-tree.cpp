/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
      
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if (curr == NULL) {
                s += "#,";
                continue;
            }

            s += to_string(curr->val) + ",";
            q.push(curr->left);
            q.push(curr->right);
        
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
         if (data == "#") return NULL;

        vector<string> nodes;
        string temp = "";

        for (char c : data) {
            if (c == ',') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < nodes.size()) {
            TreeNode* curr = q.front();
            q.pop();

            // Left child
            if (nodes[i] != "#") {
                curr->left = new TreeNode(stoi(nodes[i]));
                q.push(curr->left);
            }
            i++;

            // Right child
            if (i < nodes.size() && nodes[i] != "#") {
                curr->right = new TreeNode(stoi(nodes[i]));
                q.push(curr->right);
            }
            i++;
        }

        return root;
    } 
    };


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));