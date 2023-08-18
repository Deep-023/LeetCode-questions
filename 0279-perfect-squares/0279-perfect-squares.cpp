class Solution {
public:
    int solve(int n, vector<int>&dp){
        if(n==0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        int ans=INT_MAX;
        for(int i=sqrt(n);i>0;i--)
            ans = min(ans,solve(n-i*i,dp)+1);
        return dp[n]=ans;
    }
    
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};