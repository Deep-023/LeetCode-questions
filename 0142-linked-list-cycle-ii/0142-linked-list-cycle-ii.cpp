/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return NULL;
        
        unordered_map<ListNode*,int> m;
        ListNode* temp = head;
        while(temp!=NULL){
            if(m.count(temp))
                return temp;
            else
                m[temp]++;
            temp = temp->next;
        }
        return NULL;
    }
};