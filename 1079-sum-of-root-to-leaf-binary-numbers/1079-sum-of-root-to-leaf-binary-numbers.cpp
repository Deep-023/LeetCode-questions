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
    int ans=0;
    void dfs(TreeNode* root,string a){
        if(!root)return;
        a.push_back('0'+(root->val));
        if(!root->left && !root->right) solve(a);
        dfs(root->left,a);
        dfs(root->right,a);
    }
    void solve(string a){
        int dec = stoi(a, nullptr, 2);
        ans=ans+dec;
    }
    int sumRootToLeaf(TreeNode* root) {
        string a="";
        dfs(root,a);
        return ans;
    }
};