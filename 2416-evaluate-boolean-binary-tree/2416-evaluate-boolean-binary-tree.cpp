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
    bool evaluateTree(TreeNode* root) {
        if(root->left ==NULL && root->right == NULL)
            return root->val;
        
        bool ans;
        ans = root->val==2 ? 0 : 1;

        if(root->left)
            ans = evaluateTree(root->left);
        if(root->val==2 && root->right)
            ans = ans | evaluateTree(root->right);
        if(root->val==3 && root->right)
            ans = ans & evaluateTree(root->right);
        
        return ans;
    }
};