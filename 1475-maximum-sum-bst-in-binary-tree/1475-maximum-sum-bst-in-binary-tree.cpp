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
using pp = tuple<bool,int,int,int>;
class Solution {
public:
    int ans = 0;
    pp isBST(TreeNode* root){
        if(root==NULL) return {true,0,INT_MAX,INT_MIN};

        auto[l0,l1,l2,l3] = isBST(root->left);
        auto[r0,r1,r2,r3] = isBST(root->right);

        int subSum = 0;
        if((root->left==NULL || l3 < root->val) && (root->right==NULL || r2 > root->val) && l0 && r0){
            subSum = l1+r1+root->val;
            ans = max(ans,subSum);
            return {true,subSum,min(root->val,l2),max(root->val,r3)};
        }

        return {false,max(l2,r2),min(root->val,l2),max(root->val,r3)};
    }


    int maxSumBST(TreeNode* root) {
        isBST(root);
        return ans;
    }
};