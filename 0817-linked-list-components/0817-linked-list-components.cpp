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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        int count = nums.size();
        while(head != NULL && head->next!= NULL){
            if(m.count(head->val) && m.count(head->next->val)){
                count--;
            }
            head = head->next;
        }
        
    
        return count;
    }
};