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
    ListNode* reverseLL(ListNode* head){
        ListNode* prev=NULL, *next=NULL, *curr=head;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL && head->val==0)
            return head;
        long long sum = 0;
        ListNode* curr = reverseLL(head);
        ListNode* root = curr, *prev=NULL;
        int carry = 0;
        while(curr!=NULL){
            int val = (2*curr->val)+carry;
            carry = val/10;
            val = val%10;
            curr->val = val;
            prev = curr;
            curr=curr->next;
        }

        while(carry > 0){
            prev->next = new ListNode(carry%10);
            carry /= 10;
            prev = prev->next;
        }

        ListNode* res = reverseLL(root);
        return res;
    }
};