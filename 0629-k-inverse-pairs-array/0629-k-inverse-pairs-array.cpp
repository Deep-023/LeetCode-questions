class Solution {
public:
    
    int solve(int n, int k, vector<vector<int>>& dp){
        
        if( k == 0 ){
            return 1;
        }
        
        if(n==0)
            return 0;
        
        if(dp[n][k] != -1)
            return dp[n][k];
        
        long long ans = 0;
        
        for(int i=0;i<=min(k,n-1);i++){
            ans += solve(n-1,k-i,dp);
        }
        
        dp[n][k] = ans%((int)(1e9+7));
        return dp[n][k];
        
        
    }
    
    int kInversePairs(int n, int k) {
        vector<vector<int>>dp (n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
    }
};