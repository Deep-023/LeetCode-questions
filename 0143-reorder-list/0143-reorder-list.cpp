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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
        }
        
        ListNode* rev = slow->next, *prev = NULL, *next = NULL;
        slow->next = NULL;
        while(rev != NULL){
            next = rev->next;
            rev->next = prev;
            prev = rev;
            rev = next;
        }
        rev = prev;
        ListNode* curr = head, *revNext = NULL;
        
        while(curr != NULL && rev!= NULL){
            revNext = rev->next;
            rev->next = curr->next;
            curr->next = rev;
            curr = curr->next;
            if(curr != NULL)
                curr = curr->next;
            rev = revNext;
        } 
    }
};