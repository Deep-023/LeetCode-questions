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
    ListNode* oddEvenList(ListNode* head) {
        int odd=1;
        ListNode*temp = head;
        ListNode*left = new ListNode();
        ListNode*leftSt = left;
        ListNode*right = new ListNode();
        ListNode*rightSt = right;
        
        while(temp!=NULL){
            if(odd){
                left->next = new ListNode(temp->val);
                left = left->next;
            }else{
                right->next = new ListNode(temp->val);
                right = right->next;
            }
            odd = !odd;
            temp = temp->next;
        }
        left->next = rightSt->next;
        return leftSt->next;
        
        
    }
};