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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> sett;
        ListNode*temp = headA;
        while(temp){
            sett.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while(temp){
            if(sett.count(temp))
                return temp;
            else
                sett.insert(temp);
            temp = temp->next;
        }
        return NULL;
    }
};