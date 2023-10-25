class Solution {
public:
    
    int solve(vector<int>& val, int i, int j, vector<vector<int>>& dp){
        if(j-i <= 1){
            return 0;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = INT_MAX;
        for(int k=i+1;k<j;k++){
            ans = min(ans , solve(val,i,k,dp) + val[i]*val[k]*val[j] + solve(val,k,j,dp));
        }
        
        return dp[i][j]=ans;
    }
    
    
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(values,0,n-1,dp);
    }
};