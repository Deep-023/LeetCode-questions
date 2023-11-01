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
    
    vector<int> ans;
    int prev = INT_MIN;
    int mx = 0;
    int count = 1;
    
    void solve(TreeNode* root){
        if(root == NULL)
            return;
        
        solve(root->left);{
            
        }
        
        if(prev != INT_MIN){
            if(root->val == prev)
                count++;
            else
                count = 1;
        }   
        
        if(mx<count){
            mx = count;
            ans.clear();
            ans.push_back(root->val);
        }
        
        else if(mx==count){
            ans.push_back(root->val);
        }
        prev = root->val;
        solve(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        solve(root);
        return ans;
    }
};