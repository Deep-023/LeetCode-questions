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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        TreeNode* curr = root;
        queue<TreeNode*> q;
        q.push(curr);
        int level = 1;
        
        if(depth == 1)
            return new TreeNode(val,root,NULL);
        
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* top = q.front();
                q.pop();
                if(level == depth-1){
                    top->left = new TreeNode(val,top->left,NULL);
                    top->right = new TreeNode(val,NULL,top->right);
                }else{
                    if(top->left) q.push(top->left);
                    if(top->right) q.push(top->right);
                }
            }
            level++;
            if(level==depth)
                break;
        }
        
        return root;
    }
};