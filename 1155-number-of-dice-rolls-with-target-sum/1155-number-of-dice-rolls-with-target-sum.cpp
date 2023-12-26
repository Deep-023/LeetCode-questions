class Solution {
public:  
    int solve(int n, int idx, int k, int target, int total,vector<vector<int>>& dp){  
        int mod = 1e9+7;
        if(idx>n || target<total)
            return 0;
        
        if(n==idx && target==total)
            return 1;
        
        if(dp[idx][total] != -1)
            return dp[idx][total];
        
        int ans = 0;
        for(int i=1;i<=k;i++){
            if(i<=target){
                ans += solve(n,idx+1,k,target,total+i,dp);
                ans%=mod;
            }
        }
        
        return dp[idx][total]=ans%mod;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(n,0,k,target,0,dp);
    }
};