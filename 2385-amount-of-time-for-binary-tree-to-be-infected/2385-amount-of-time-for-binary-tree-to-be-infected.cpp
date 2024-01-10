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
    
    void dfs(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent, int start, TreeNode*& base){
        
        if(root==NULL)
            return;
        
        if(root->val==start)
            base = root;
        
        if(root->left != NULL){
            parent[root->left] = root;
            dfs(root->left,parent,start,base);
        }
        
        if(root->right != NULL){
            parent[root->right] = root;
            dfs(root->right,parent,start,base);
        } 
    }
    
    int amountOfTime(TreeNode* root, int start) {
            
        unordered_map<TreeNode*,bool> burned;
        unordered_map<TreeNode*,TreeNode*> parent;
        parent[root] = NULL;
        TreeNode* base = NULL;
        int mx = INT_MIN;
        
        dfs(root,parent,start,base);
        queue<pair<TreeNode*,int>> q;
        q.push({base,0});
        
        while(!q.empty()){
            TreeNode* temp = q.front().first;
            int minute = q.front().second;
            burned[temp] = true;
            q.pop();
            
            mx = max(mx,minute);
            
            if(temp->left != NULL && !burned[temp->left]){
                q.push({temp->left,minute+1});
            }
            if(temp->right != NULL && !burned[temp->right]){
                q.push({temp->right,minute+1});
            }
            if(parent[temp] != NULL && !burned[parent[temp]]){
                q.push({parent[temp],minute+1});
            }
        }
        
        return mx;
        
    }
};