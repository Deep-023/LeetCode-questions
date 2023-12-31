/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        //int ind = find(arr.begin(),arr.end(),x) - arr.begin();
        int n = arr.size();
        for(int i=1;i<n;i++){
            int k=i-1;
            if(arr[i]<x){
                while(k>=0 && arr[k]>=x){
                    swap(arr[k],arr[k+1]);
                    k--;
                }
            }
        }
        temp = head;
        for(int i:arr){
            temp->val = i;
            temp = temp->next;
        }
        return head;
    }
};*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* leftStart = new ListNode();
        ListNode* rightStart = new ListNode();
        ListNode* leftEnd = leftStart;
        ListNode* rightEnd = rightStart;
        
        while(head!=NULL){
            if(head->val < x){
                leftEnd->next = head;
                leftEnd= leftEnd->next;
            }else{
                rightEnd->next = head;
                rightEnd = rightEnd->next;
            }
            head = head->next;
        }
        rightEnd->next = NULL;
        leftEnd->next = rightStart->next;
        return leftStart->next;
    }
};