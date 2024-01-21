class Solution {
public:
    int solve(vector<int>& arr, int n, int idx, bool take,vector<vector<int>>& dp){
        
        if(idx>=n)
            return 0;
        
        if(dp[idx][take] != -1)
            return dp[idx][take];
        
        int ans = INT_MIN;
        
        
        if(take){
            ans = max(ans, arr[idx]+solve(arr,n,idx+1,false,dp));
        }
        
        ans = max(ans, solve(arr,n,idx+1,true,dp));
        
        return dp[idx][take]=ans;
        
    }

    int rob(vector<int>& arr) {
        int n= arr.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(arr,n,0,true,dp);
    }
};