class Solution {
public:
    int solve(int row, int col, int m, int n, vector<vector<int>>& dp){
        if(row==m-1 && col==n-1){
            return 0;
        }
        
        if(dp[row][col]!= -1)
            return dp[row][col];
        
        if(row+1 < m){
            dp[row][col] += solve(row+1,col,m,n,dp)+1;
        }
        if(col+1 < n){
            dp[row][col] += solve(row,col+1,m,n,dp)+1;
        }
        return dp[row][col];
    }
    
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp)+1;
    }
};