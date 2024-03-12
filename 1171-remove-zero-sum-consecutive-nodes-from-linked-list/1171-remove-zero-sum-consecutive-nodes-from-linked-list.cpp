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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> mp;
        ListNode* curr = head;
        mp[0] = NULL;
        int sum = 0;
        while(curr != NULL){
            sum +=  curr->val;
            if(mp.count(sum)){
                if(mp[sum] != NULL){
                    mp[sum]->next = curr->next;
                    mp.clear();
                    curr = head;
                    mp[0] = NULL;
                    sum = 0;
                    continue;
                }
                else
                    head = curr->next;
            }
            if(!mp.count(sum))
                mp[sum] = curr;
            curr = curr->next;
        }
        
        return head;
    }
};