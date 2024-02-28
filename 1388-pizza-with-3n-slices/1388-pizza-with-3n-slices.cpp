class Solution {
public:
    int solve(vector<int>& slices, int i, int n, int k ,vector<vector<int>>& dp){
        if(i>=n || k==0)
            return 0;
        
        if(dp[i][k] != -1){
            return dp[i][k];
        }
        
        int ans = INT_MIN;
        ans = solve(slices,i+1,n,k,dp);
        ans = max(ans, slices[i]+solve(slices,i+2,n,k-1,dp));
        
        return dp[i][k] = ans;
    }
    
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int k = n/3;
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        vector<vector<int>> dp2(n+1,vector<int>(k+1,-1));
        int ans = solve(slices,0,n-1,k,dp);
        ans = max(ans,solve(slices,1,n,k,dp2));
        return ans;
    }
};