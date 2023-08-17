class Solution {
public:
    
    bool solve(vector<int>& nums, int idx, int target, vector<vector<int>>&dp, int n){
        if(idx>=n) return 0;
        if(target<0) return 0;
        if(target==0) return 1;
        if(dp[idx][target]!=-1)
            return dp[idx][target];
        
        return dp[idx][target] = solve(nums,idx+1,target-nums[idx],dp,n) || solve(nums,idx+1,target,dp,n);
    }
    
    bool canPartition(vector<int>& nums) {
        int n =nums.size();
        int total = 0;
        for(int i=0;i<n;i++){
            total += nums[i];
        }
        if(total&1) return 0;
        total = total/2;
        vector<vector<int>>dp(n,vector<int>(total+1,-1));
        return solve(nums,0,total,dp,n);
    }
};