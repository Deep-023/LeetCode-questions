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
typedef pair<int,pair<int,int>> pp;
class Solution {
public:
    
    int ans=0;
    void solve(TreeNode* root,int val){
        if(root==NULL){
            return;
        }
        
        val = val*10+root->val;
        
        if(root->left==NULL && root->right==NULL)
        {
            ans += val;
            return;
        }
        
        solve(root->left,val);
        solve(root->right,val);
    }
    
    int sumNumbers(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};