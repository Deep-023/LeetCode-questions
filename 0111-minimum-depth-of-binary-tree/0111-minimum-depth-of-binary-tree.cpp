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
    int minDep = INT_MAX;
    void solve(TreeNode* root , int count){
        if(root->left == NULL && root->right == NULL){
            minDep = min(minDep, count);
            return;
        }
        if(root->left != NULL)
            solve(root->left, count+1);
        if(root->right != NULL)
            solve(root->right, count+1);
    }
    
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        solve(root,1);
        return minDep;
    }
};