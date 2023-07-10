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
    int longest = 0;
    void solve(TreeNode*root, int track, int count){ //0 for left and 1 for right
        longest = max(longest,count);
        
        if(!root->left && !root->right)
            return;
        
        if(!track){
            if(root->right) {
                solve(root->right, !track, count+1);
            }
            if(root->left)
                solve(root->left, track , 1);
            
        }
        else{
            if(root->left){
                solve(root->left, !track, count+1);
            }
            if(root->right) 
                solve(root->right, track , 1);
            
        }
    }
    
    
    int longestZigZag(TreeNode* root) {
        if(!root)
            return 0;
        if(root->left)
            solve(root->left,0,1);
        if(root->right)
            solve(root->right,1,1);
        return longest;
        
    }
};