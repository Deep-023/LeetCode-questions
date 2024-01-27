class Solution {
public:
    
    /*int solve(int n, int k, vector<vector<int>>& dp){
        
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
    }*/
    
    int kInversePairs(int n, int k) {
        /*vector<vector<int>>dp (n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);*/
        
        int mod = 1e9+7;
        vector<long long> curr(k+1,0),last(k+1,0);
        last[0] = 1;
        curr[0] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                curr[j] = (curr[j-1]+last[j])%mod; // last is prev state, so the k will be same and only n has increased mean we can place the number as it is in the end and curr[j-1] i.e k inverse pair if we add 5 it will make it k
                if(j>=i)
                    curr[j] = (curr[j]-last[j-i] + mod)%mod; // +mod to eliminate mods of -ve numbers
            }
            last = curr;
        }
        
        
        return curr[k];
    }
};