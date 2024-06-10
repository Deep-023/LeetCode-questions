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
    TreeNode* solve(vector<int>& pre, vector<int>& in, int l, int r, int& idx) {
        if(idx>=pre.size() || l>=r)
            return NULL;
        if(l==r-1){
            return new TreeNode(pre[idx++]);
        }

        TreeNode* root = new TreeNode(pre[idx]);
        cout<<pre[idx]<<" ";
        int pos = find(in.begin()+l,in.begin()+r,pre[idx++])-(in.begin()+l);
        if(pos>=0 && pos<(r-l)){
            root->left = solve(pre,in,l,l+pos,idx);
            root->right = solve(pre,in,l+pos+1,r,idx);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        return solve(preorder,inorder,0,preorder.size(),i);
    }
};