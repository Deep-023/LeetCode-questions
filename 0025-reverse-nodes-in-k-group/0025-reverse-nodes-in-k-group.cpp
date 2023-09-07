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
    ListNode* solve(ListNode* head, int k, int n) {
        
        if(head == NULL || n<k)
            return head;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        int count =0;
        
        while(curr != NULL && count<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        if(next!=NULL){
            head->next = solve(next,k,n-k);
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int size=0;
        while(temp!=NULL){
            size++;
            temp =  temp->next;
        }
        return solve(head,k,size);
    }
};