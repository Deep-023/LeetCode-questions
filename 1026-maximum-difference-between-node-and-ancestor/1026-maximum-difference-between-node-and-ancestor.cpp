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
    void solve(TreeNode* root, int mx, int mn, int& ans){
        if(mx != INT_MIN && mn != INT_MAX)
            ans = max(ans,mx-mn);
        
        if(root==NULL){
            return;
        }
        
        solve(root->left, max(mx,root->val), min(mn,root->val), ans);
        solve(root->right, max(mx,root->val), min(mn,root->val), ans);
        
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        solve(root,INT_MIN,INT_MAX,ans);
        return ans;
    }
};