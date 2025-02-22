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
    TreeNode* solve(string& traversal, int st, int ed){
        
        if(st>=ed)
            return NULL;
        
        int num = 0;
        while(traversal[st]!='-' && st<ed){
            num = num*10+(traversal[st++]-'0');
        }

        TreeNode* newNode = new TreeNode(num);
        int cnt = 0;
        while(traversal[st]=='-' && st<ed){
            st++;cnt++;
        }
        int cnt2 = 0,i;
        for(i=st;i<ed;i++){
            if(traversal[i]=='-')
                cnt2++;
            else{
                if(cnt==cnt2) break;
                else cnt2=0;
            }
        }
        newNode->left = solve(traversal,st,i-cnt2);
        if(i<ed)
            newNode->right = solve(traversal,i,ed);

        return newNode;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        return solve(traversal,0,traversal.size()); 
    }
};