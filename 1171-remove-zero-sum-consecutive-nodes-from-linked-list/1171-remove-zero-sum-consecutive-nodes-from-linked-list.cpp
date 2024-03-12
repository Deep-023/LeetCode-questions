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
        ListNode* prev = NULL;
        mp[0] = NULL;
        int sum = 0;
        while(curr != NULL){
            if(curr->val==0){
                if(prev != NULL)
                    prev->next = curr->next;
                else
                    head = head->next;
                curr = curr->next;
                continue;
            }
            sum += curr->val;
            if(mp.find(sum) != mp.end()){
                if(mp[sum] != NULL){
                    mp[sum]->next = curr->next;
                }else{
                    head = curr->next;
                }
                mp.clear();
                curr = head;
                mp[0] = NULL;
                sum = 0;
                prev = NULL;
                continue;
                
            }else{
                mp[sum] = curr;
            }
           
            prev = curr;
            curr = curr->next;
        }
        
        return head;
    }
};