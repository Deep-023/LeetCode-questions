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
    
    void dfs(TreeNode* root, vector<int>& leaf){
        
        if(root == NULL)
            return;
        
        if(root->left==NULL && root->right==NULL){
            leaf.push_back(root->val);
            return;
        }
        
        dfs(root->left, leaf);
        dfs(root->right,leaf);
        
    }
    
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        int i=0;
        vector<int> leaf,leaf2;
        dfs(root1, leaf);
        dfs(root2,leaf2);
        
        if(leaf.size() != leaf2.size())
            return false;
        
        for(int i=0;i<leaf.size();i++){
            if(leaf[i]!=leaf2[i])
                return false;
        }
        
        return true;
    }
};