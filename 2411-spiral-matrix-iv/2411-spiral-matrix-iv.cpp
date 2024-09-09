/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isTurn(vector<vector<int>>& ans, int i, int j, int m, int n){
        return i>=m || j>=n || i<0 || j<0 || ans[i][j] != -1;
    }
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int i=0,j=0,k=0;
        ListNode* curr = head;
        while(curr != NULL){
            ans[i][j] = curr->val;
            curr = curr->next;
            if(isTurn(ans,i+dir[k][0],j+dir[k][1],m,n)){
                k = (k+1)%4;
            }
            i += dir[k][0];
            j += dir[k][1];
        }
        return ans;
    }
};