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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
         vector<ListNode*> result;
        int length=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            length++;
            temp=temp->next;
        }
        int repeat=length/k;
        int extraNodes = length % k;
        temp=head;
        while(temp!=NULL&&k>0)
        {
            ListNode* head_temp=temp;
            int rep= repeat+(extraNodes-- > 0 ? 1 : 0);
            rep--;
            while(rep>0&&temp!=NULL)
            {
                temp=temp->next;
                rep--;
            }
            k--;
            result.push_back(head_temp);
            ListNode* temp1=temp;
            if(temp==NULL||temp->next==NULL)
                break;
            else
                temp=temp->next;
            temp1->next=NULL;
        }
        while(k>0)
        {
           result.push_back(NULL);
            k--;
        }
        return result;
        
    }
};