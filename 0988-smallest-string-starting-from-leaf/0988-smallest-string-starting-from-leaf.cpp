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
    void solve(TreeNode* root, string& ans, string& temp){
        
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            temp.push_back(root->val+'a');
            reverse(temp.begin(),temp.end());
            if(ans=="" || ans>temp)
                ans=temp;
            reverse(temp.begin(),temp.end());
            temp.pop_back();
            return;
        }
        
        
        temp.push_back(root->val+'a');
        
        solve(root->left,ans,temp);
        solve(root->right,ans,temp);
        
        temp.pop_back();
        
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        string temp = "";
        solve(root,ans,temp);
        
        return ans;
    }
};