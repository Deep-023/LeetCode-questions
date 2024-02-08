class Solution {
public:
    
    int solve(int n, vector<int>& dp){
        if(n==0)
            return 0;
        if(n<0)
            return 1e9;
        
        if(dp[n] != -1)
            return dp[n];
        
        int temp = 1e9+7;
        for(int i=1;i*i<=n;i++){
            temp = min(temp , solve(n-i*i,dp)+1);
        }
        
        return dp[n]=temp;
    }
    
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};