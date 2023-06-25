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
    
    string add(string s1, string s2){
        int n1 = s1.size(), n2 = s2.size(), carry=0;
        string res;
        while(n1 && n2){
            int a = (s1[n1-1]-'0')+(s2[n2-1]-'0')+carry;
            res.push_back((a%10)+'0');
            carry = a/10;
            n1--;n2--;
        }
        while(n1){
            int a;
            if(carry){
            a = (s1[n1-1]-'0')+carry;
            carry = a/10;
            }
            else
            a = (s1[n1-1]-'0');
            res.push_back((a%10)+'0');
            n1--;
        }
         while(n2){
            int a;
            if(carry){
            a = (s2[n2-1]-'0')+carry;
            carry = a/10;
            }
            else
            a = (s2[n2-1]-'0');
            res.push_back((a%10)+'0');
            n2--;
        }
        if (carry)
            res.push_back(carry+'0');
        return res;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1, s2;
        ListNode* node = l1;
        while(node!=NULL){
            s1.push_back(node->val+'0');
            node = node->next;
        }
        node = l2;
        while(node!=NULL){
            s2.push_back(node->val+'0');
            node = node->next;
        }
        string res = add(s1,s2);
        reverse(res.begin(),res.end());
        node = new ListNode(res[0]-'0');
        ListNode* p = node;
        for(int i=1;i<res.size();i++){
            ListNode* p = new ListNode(res[i]-'0');
            node->next = p;
            node = node->next;
        }
        
        return p;
    }
};