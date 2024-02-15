class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        if(nums.size() < 3)
            return -1;
        
        priority_queue<int> pq;
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            sum += nums[i];
        }
        
        while(!pq.empty() && ((sum-pq.top()) <= pq.top())){   
            sum = sum-pq.top();
            pq.pop();
        }
        
        return sum==0?-1:sum;
    }
};