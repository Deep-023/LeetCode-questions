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
    
    void dfsParent(unordered_map<TreeNode* , TreeNode*>& parent, TreeNode* root){
        if(!root)
            return;
        if(root->left)
            parent[root->left] = root;
        if(root->right)
            parent[root->right] = root;
        
        dfsParent(parent,root->left);
        dfsParent(parent,root->right);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parent;
        dfsParent(parent , root);
        unordered_map<TreeNode*, bool> visited;
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int len = 0;
        while(!q.empty()){
            int n = q.size();
            if(len == k)
                break;
            len++;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(parent[node] && !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
        }
         int n = q.size();
        while(n--){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};