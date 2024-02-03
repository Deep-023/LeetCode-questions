class Solution {
public:
    
    int solve(int ind, int n, vector<int>& arr, int k, vector<int>& dp){
        if(ind>=n){
            return 0;
        }
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int mx = 0;
        int ans = INT_MIN;
        for(int i=ind;i<ind+k && i<n;i++){
            mx = max(mx,arr[i]);
            ans = max(ans, (mx*(i-ind+1)) + solve(i+1,n,arr,k,dp));
        }
        return dp[ind]=ans;        
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n,-1);
        return solve(0,n,arr,k,dp);
        
    }
};