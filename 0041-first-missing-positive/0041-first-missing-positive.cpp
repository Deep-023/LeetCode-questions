class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());
        while(!pq.empty() && pq.top()<=0){
            pq.pop();
        }
        int i = 1;
        while(!pq.empty()){
            if(pq.top() != i)
                return i;
            else{
                while(!pq.empty() && pq.top() == i)
                    pq.pop();
            }
            i++;
        }
        
        return i;
    }
};