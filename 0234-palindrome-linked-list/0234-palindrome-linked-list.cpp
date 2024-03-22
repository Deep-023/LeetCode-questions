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
        ListNode* slow = head;
        ListNode* fast = head->next;
    
        while(fast!= NULL && fast->next!= NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast)
                fast = fast->next;
        }
        
        ListNode* md = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;
        
        while(md!=NULL){
            nxt = md->next;
            md->next = prev;
            prev = md;
            md = nxt;
        }
        
        slow = head;
        md = prev;
        
        while(prev != NULL && slow != NULL){
            if(prev->val != slow->val)
                return false;
            prev = prev->next;
            slow = slow->next;
        }
        
        return true;
        
    }
};