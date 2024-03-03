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
    
    ListNode* solve(ListNode* node, int n, int& count, ListNode* parent){
        if(node==NULL)
            return NULL;
        
        solve(node->next,n,count,node);
        count++;
        
        if(count==n){
            if(parent != NULL)
                parent->next = node->next;
            else
                node = node->next;
        }
        
        return node;
        
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        
        head = solve(head,n,count,NULL);
        return head;
    }
};