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
    bool isPalindrome(ListNode* head) {
        ListNode* end = head;
        vector<int> pal;
        while(end!=NULL){
            pal.push_back(end->val);
            end = end->next;
        }
        int n= pal.size();
        int j= n-1,i=0;
        while(i<j){
            if(pal[i++]!=pal[j--])
                return false;
        }
        return true;
    }
        
};