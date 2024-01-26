class Solution {
public:
    
    int solve(int m, int n, int moves, int i, int j, vector<vector<vector<int>>>& dp){
        if(i>=m || j>=n || i<0 || j<0){
            return 1;
        }
        
        if(moves <= 0)
            return 0;
        
        if(dp[i][j][moves] != -1)
            return dp[i][j][moves];
        
        long long ans= 0;
        ans += solve(m,n,moves-1,i+1,j,dp);
        ans += solve(m,n,moves-1,i-1,j,dp);
        ans += solve(m,n,moves-1,i,j+1,dp);
        ans += solve(m,n,moves-1,i,j-1,dp);
        ans %= ((int)1e9+7);
        
        return dp[i][j][moves]=ans;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return solve(m,n,maxMove,startRow,startColumn,dp);
    }
};