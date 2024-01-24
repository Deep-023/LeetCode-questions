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
    
    void solve(TreeNode* root, int* arr, int& ans, int check ){
        
        if(root == NULL){
            return;
        }
        
        if(arr[root->val]==1){
            arr[root->val] = 0;
            check--;
            
        }else if(arr[root->val]==0){
            arr[root->val] = 1;
            check++;
        }
        
        if((root->left==NULL && root->right==NULL) && (check==0 || check==1))
                ans++;
        
        solve(root->left,arr,ans,check);
        solve(root->right,arr,ans,check);
        
        if(arr[root->val]==1){
            arr[root->val] = 0;
        }else if(arr[root->val]==0){
            arr[root->val] = 1;
        }
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        int arr[10];
        for(int i=0;i<10;i++)
            arr[i]=0;
        int ans = 0;
        solve(root,arr,ans,0);
        return ans;
        
    }
};