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
    bool isEvenOddTree(TreeNode* root) {
        int flag = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size(),mx;
            mx = flag==1 ? INT_MAX : INT_MIN;
            
            while(size){
                TreeNode* top = q.front();
                int num = top->val;
                q.pop();
                
                if(flag == 1){
                    if(mx>num && !(num&1)){
                        mx = num;
                    }else{
                        return false;
                    }
                }else{
                    if(mx<num && num&1){
                        mx = num;
                    }else{
                        return false;
                    }
                }
                
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
                size--;
            }
            flag = !flag;
        }
        
        return true;
    }
};