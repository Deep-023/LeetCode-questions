class Solution {
public:
    int solve(vector<int>& nums,int idx, int target, int sum, int n, unordered_map<int,unordered_map<int,int>>& dp){
        if(idx==n){
            if(target==sum)
                return 1;
            else 
                return 0;
        }
        
        if(dp[idx].find(sum) != dp[idx].end()){
            return dp[idx][sum];
        }
        
        return dp[idx][sum] = solve(nums,idx+1,target,sum+nums[idx],n,dp)+solve(nums,idx+1,target,sum-nums[idx],n,dp);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,unordered_map<int,int>> dp;
        return solve(nums,0,target,0,nums.size(),dp);
    }
};