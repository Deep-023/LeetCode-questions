class Solution {
public:
    
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int left = 0,n = nums.size(),sum = 1,ans = 0;
        for(int right = 0; right<n; right++){
            
            sum *= nums[right];
            while(sum>=k && left<=right){
                sum /= nums[left++];
            }
            ans += right-left+1;
        }
        
        return ans;
    }
};