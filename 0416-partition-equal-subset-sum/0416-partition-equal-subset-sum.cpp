class Solution {
public:
    int n;
    bool solve(int idx, int sum1, int finalSum, vector<int>& nums, vector<vector<int>>& dp){
        
        if(sum1==finalSum)
            return true;
        
        if(sum1>finalSum || idx>=n)
            return false;
        
        if(dp[idx][sum1]!=-1)
            return dp[idx][sum1];
        
        return dp[idx][sum1] = solve(idx+1,sum1,finalSum,nums,dp) || solve(idx+1,sum1+nums[idx],finalSum,nums,dp);
        
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        double sum = accumulate(nums.begin(),nums.end(),0)*1.0/2;
        if(sum != (int)sum)
            return false;
        vector<vector<int>> dp(n,vector<int>((int)sum+1,-1));
        return solve(0, 0, sum, nums, dp);
    }
};