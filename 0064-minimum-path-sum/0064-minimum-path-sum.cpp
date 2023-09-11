class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j,int m, int n,  vector<vector<int>>& dp){
        
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }
        
        if(i>=m || j>=n)
            return 500;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int count = solve(grid,i+1,j,m,n,dp)+grid[i][j];
        count = min(count, solve(grid,i,j+1,m,n,dp) +grid[i][j]);
        return dp[i][j] = count;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid[0].size(), m=grid.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(grid,0,0,m,n,dp);
    }
};