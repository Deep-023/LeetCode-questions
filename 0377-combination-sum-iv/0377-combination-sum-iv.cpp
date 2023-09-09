class Solution {
public:
    int solve(vector<int>& nums, int target, int idx, vector<int>&dp, int n){
        if(target==0){
            return 1;
        }
        
        if(target<0 || idx >= n)
            return 0;
        
        if(dp[target] != -1)
            return dp[target];
        
        dp[target] = 0;
        for(int i=0;i<n;i++){
            dp[target] += solve(nums,target-nums[i],idx,dp,n);
        }
        
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return solve(nums, target, 0,dp,nums.size());
    }
};