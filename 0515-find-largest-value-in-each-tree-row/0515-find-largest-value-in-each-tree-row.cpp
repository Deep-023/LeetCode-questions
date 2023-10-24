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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root==NULL)
            return {};
        q.push(root);
        while(!q.empty()){
            int num = INT_MIN;
            int size = q.size();
            while(size-->0){
                TreeNode* temp = q.front();
                num = max(num,temp->val);
                q.pop();
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
            }
            ans.push_back(num);
        }
        return ans;
    }
};