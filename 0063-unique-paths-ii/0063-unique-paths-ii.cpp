class Solution {
public:
    int ans=0;
    bool isSafe(vector<vector<int>>& og, int i, int j){
        return og[i][j] == 0;
    }
    
    int solve(vector<vector<int>>& og, int i, int j,int n, int m,vector<vector<int>>& dp){
        if(i==n-1 && j==m-1){
            return dp[i][j]=1;
        }
        
        if(i>=n || j>=m)
            return 0;
        
        if(dp[i][j]!= -1)
            return dp[i][j];
        
        dp[i][j]=0;
        if(i+1<n && isSafe(og,i+1,j)){
            if(solve(og,i+1,j,n,m,dp))
                dp[i][j] += dp[i+1][j];
        }
        if(j+1<m && isSafe(og,i,j+1)){
            if(solve(og,i,j+1,n,m,dp))
                dp[i][j] += dp[i][j+1];
        }
        
        return dp[i][j];     
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int n = og.size();
        int m= og[0].size();
        if(og[0][0]==1)
            return 0;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return solve(og,0,0,n,m,dp);
    }
};