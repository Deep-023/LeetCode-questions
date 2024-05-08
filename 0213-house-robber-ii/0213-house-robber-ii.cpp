class Solution {
public:
    int dp[101][2];
    int solve(vector<int>& nums, int idx, int n, int take){
        if(idx>n)
            return 0;
        
        if(dp[idx][take]!=-1)
            return dp[idx][take];
        
        int ans = 0;
        if(take){
            ans = nums[idx]+solve(nums,idx+1,n,false);
        }
        
        ans = max(ans,solve(nums,idx+1,n,true));
        return dp[idx][take] = ans;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        memset(dp,-1,sizeof(dp));
        int ans = solve(nums,0,n-2,true);
        memset(dp,-1,sizeof(dp));
        ans = max(ans,solve(nums,1,n-1,true));
        return ans;
    }
};