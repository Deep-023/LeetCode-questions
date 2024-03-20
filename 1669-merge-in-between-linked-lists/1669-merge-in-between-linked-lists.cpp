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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    
        ListNode* list2end = list2;
        while(list2end != NULL && list2end->next != NULL)
            list2end = list2end->next;
        
        int count = 0;
        ListNode* prev = NULL;
        ListNode* curr = list1;
        while(curr != NULL){
            if(count == a){
                if(prev != NULL)
                    prev->next = list2;
                else
                    list1 = list2;
            }
            if(count == b){
                list2end->next = curr->next;
            }
            prev = curr;
            curr = curr->next;
            count++;
        }
        return list1;
    }
};