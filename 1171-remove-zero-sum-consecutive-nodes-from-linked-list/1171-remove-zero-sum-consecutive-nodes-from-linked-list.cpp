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
        ListNode* temp = new ListNode();
        temp->next = head;
        ListNode* curr =  temp;
        int sum = 0;
        while(curr != NULL){
            sum += curr->val;
            if(mp.find(sum) != mp.end()){
                ListNode* st = mp[sum]->next;
                int p = sum + st->val;
                while(p != sum){
                    mp.erase(p);
                    st = st->next;
                    p += st->val;
                }
                mp[sum]->next = curr->next;
            }else{
                mp[sum] = curr;
            }
            curr = curr->next;
        }
        return temp->next;
    }
};