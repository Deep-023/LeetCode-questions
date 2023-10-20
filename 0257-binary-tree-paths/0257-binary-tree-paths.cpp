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
    
    vector<string> ans;
    
    void solve( TreeNode*root, string output ){
        if(root==NULL)
            return;
        
        if(output.size()>0){
            output.push_back('-');
            output.push_back('>');
        }
        
        output += to_string(root->val);
        
        if(root->left==NULL && root->right==NULL){   
            ans.push_back(output);
            return;
        }
        
        solve(root->left,output);
        solve(root->right,output);
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root,"");
        return ans;
    }
};