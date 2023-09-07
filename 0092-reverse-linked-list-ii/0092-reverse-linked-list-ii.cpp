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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        ListNode* ans = new ListNode();
        ListNode* anshead = ans;
        int count = 1;
        while(temp!=NULL){
            if(count==left){
                ListNode* temp1 = new ListNode(temp->val);
                ListNode* temphead = temp1;
                while( temp->next != NULL && count<right){
                    temp = temp->next;
                    ListNode* temp2 = new ListNode(temp->val);
                    temp2->next = temp1;
                    temp1 = temp2;
                    count++;
                }
                ans->next = temp1;
                ans = temphead;
            }else{
                ans->next = new ListNode(temp->val);
                ans = ans->next;
            }
            count++;
            temp = temp->next;
            
        }
        return anshead->next;
        
    }
};