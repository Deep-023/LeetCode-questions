class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;
        int target = sum/2;
        
        vector<int> dp(target+1);
        dp[0] = 1;
        for(int i=0;i<nums.size();i++){
            for(int j=target;j>=nums[i];j--){
                if(j-nums[i]>=0) dp[j] = max(dp[j],dp[j-nums[i]]);
            }
        }

        return dp[target]>0;
    }
};