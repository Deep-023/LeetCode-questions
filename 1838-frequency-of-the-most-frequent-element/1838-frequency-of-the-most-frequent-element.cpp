class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long int sum = 0;
        int left=0,right=0;
        int mx = INT_MIN;
        
        for(right =0;right<nums.size();right++){
            sum += nums[right];
            
            while((((long long)nums[right])*(right-left+1)- sum) > k){
                sum -= nums[left++];
            }
            
            mx = max(mx, right-left+1);
            
        }
        
        return mx;
    }
};