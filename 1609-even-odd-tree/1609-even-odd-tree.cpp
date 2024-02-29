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
            
            if(flag)
                mx = INT_MAX;
            else
                mx = INT_MIN;
            
            while(size){
                TreeNode* top = q.front();
                q.pop();
                
                if(flag == 1){
                    if(mx>top->val && !(top->val&1)){
                        mx = top->val;
                    }else{
                        //cout<<mx<<" "<<top->val<<" "<<flag<<endl;
                        return false;
                    }
                }else{
                    if(mx<top->val && top->val&1){
                        mx = top->val;
                    }else{
                        //cout<<mx<<" "<<top->val<<" "<<flag<<endl;
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